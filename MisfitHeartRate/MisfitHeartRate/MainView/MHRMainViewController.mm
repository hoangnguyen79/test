//
//  MHRMainViewController.m
//  opticalHeartRate
//
//  Created by Bao Nguyen on 6/23/14.
//  Copyright (c) 2014 misfit. All rights reserved.
//

#import "MHRMainViewController.hpp"
#import "UIImageCVMatConverter.hpp"
#import "matlab.h"

const int CAMERA_WIDTH = 352;
const int CAMERA_HEIGHT = 288;
const int IMAGE_WIDTH = 256;
const int IMAGE_HEIGHT = 256;
const int WIDTH_PADDING = (CAMERA_WIDTH-IMAGE_WIDTH)/2;
const int HEIGHT_PADDING = (CAMERA_HEIGHT-IMAGE_HEIGHT)/2;
static NSString * const FACE_MESSAGE = @"Make sure your face fitted in the Aqua rectangle!";
static NSString * const FINGER_MESSAGE = @"Completely cover the back-camera and the flash with your finger!";


@interface MHRMainViewController ()
{
    BOOL isCapturing;
    cv::Rect cropArea;
}

@property (retain, nonatomic) CvVideoCamera *videoCamera;
@property (assign, nonatomic) VideoWriter videoWriter;
@property (strong, nonatomic) NSString *outPath;
@property (strong, nonatomic) NSString *outFile;
@property (assign, nonatomic) NSInteger nFrames;

@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@property (weak, nonatomic) IBOutlet UIButton *startButton;
@property (weak, nonatomic) IBOutlet UISwitch *cameraSwitch;
@property (weak, nonatomic) IBOutlet UIButton *stopButton;
@property (weak, nonatomic) IBOutlet UILabel *faceLabel;
@property (weak, nonatomic) IBOutlet UILabel *fingerLabel;

@end


@implementation MHRMainViewController

@synthesize videoCamera = _videoCamera;
@synthesize videoWriter = _videoWriter;
@synthesize cameraSwitch = _cameraSwitch;
@synthesize outPath = _outPath;
@synthesize outFile = _outFile;
@synthesize nFrames = _nFrames;


- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}


- (void)viewDidLoad
{
    [super viewDidLoad];
    NSString *resourcePath = [[NSBundle mainBundle] resourcePath];
    NSString *filePath = [resourcePath stringByAppendingPathComponent:@"test.mp4"];
    NSLog(@"filePath = %@", filePath);
    NSFileManager *fileManager = [NSFileManager defaultManager];
    if (![fileManager fileExistsAtPath:filePath])
    {
        NSLog(@"file is not exists!");
    }
   
    _videoCamera = [[CvVideoCamera alloc] initWithParentView:self.imageView];
    _videoCamera.delegate = self;
    _videoCamera.defaultAVCaptureDevicePosition = AVCaptureDevicePositionFront;
    _videoCamera.defaultAVCaptureVideoOrientation = AVCaptureVideoOrientationLandscapeLeft;
    _videoCamera.defaultAVCaptureSessionPreset = AVCaptureSessionPreset352x288;
    _videoCamera.defaultFPS = _frameRate;
    _videoCamera.rotateVideo = YES;
    _videoCamera.grayscaleMode = NO;
    [_videoCamera start];
    
    isCapturing = NO;
    cropArea = cv::Rect(WIDTH_PADDING, HEIGHT_PADDING, IMAGE_WIDTH, IMAGE_HEIGHT);
    
    [self drawCameraCaptureRect:@"MHRCameraCaptureRect"];
//    [self startButtonDidTap:self];
}


-(void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    _videoWriter.release();
}


- (void)didReceiveMemoryWarning
{
    //[super didReceiveMmoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)startButtonDidTap:(id)sender
{
//    test_ideal_bandpassing();
//    testMathFunctions();
//    test_fft();
//    return;

    // create new directory for this session
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentationDirectory, NSUserDomainMask, YES);
    _outPath = [paths objectAtIndex:0];
    _outPath = [_outPath substringToIndex:([_outPath length] - [@"Library/Documentation/" length] + 1)];
    NSDateFormatter *formater = [[NSDateFormatter alloc] init];
    formater.dateFormat = @"yyyy-MM-dd-HH-mm-ss";
    _outPath = [_outPath stringByAppendingFormat:@"Documents/%@/",
                [formater stringFromDate:[NSDate date]]];
    [MHRUtilities createDirectory:_outPath];
    
    // output new file to write input video
    _outFile = [_outPath stringByAppendingString:@"input.mp4"];
    _videoWriter.open([_outFile UTF8String],
                      CV_FOURCC('M','P','4','2'),
                      _frameRate,
                      cvSize(IMAGE_WIDTH, IMAGE_HEIGHT),
                      true);
    
    isCapturing = YES;
    _startButton.enabled = NO;
    _cameraSwitch.enabled = NO;
    _nFrames = 0;
    
//     NSString *resourcePath = [[NSBundle mainBundle] resourcePath];
//    run_algorithms([resourcePath UTF8String], "test0.mp4", [_outPath UTF8String]);
//    run_algorithms([resourcePath UTF8String], "2014-06-10-Self-Face_crop.mp4", [outputPath UTF8String]);
}


- (IBAction)stopButtonDidTap:(id)sender
{
    if (isCapturing)
    {
        isCapturing = NO;
        _startButton.enabled = YES;
        _cameraSwitch.enabled = YES;
        [self drawCameraCaptureRect:@"MHRWhiteColor"];
        [_videoCamera stop];
        _videoWriter.release();
        
        __block hrResult result(-1, -1);
        if (!_cameraSwitch.isOn)
        {
            _fingerLabel.text = @"";
        }
        _faceLabel.text = @"Processing....";
        [MBProgressHUD showHUDAddedTo:self.view animated:YES];
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0), ^{
            printf("nFrames = %d\n", _nFrames);
            result = run_algorithms([_outPath UTF8String], "input.mp4", [_outPath UTF8String]);
//              NSString *resourcePath = [[NSBundle mainBundle] resourcePath];
//              result = run_algorithms([resourcePath UTF8String], "test0.mp4", [_outPath UTF8String]);
//          result = run_algorithms([resourcePath UTF8String], "2014-06-10-Self-Face_crop.mp4", [outputPath UTF8String]);
            dispatch_async(dispatch_get_main_queue(), ^{
                // show result
                MHRResultViewController *resultView = [[MHRResultViewController alloc] init];
                resultView.autocorrResult = result.autocorr;
                resultView.pdaResult = result.pda;
                [self.navigationController pushViewController:resultView animated:YES];
                // update UI
                [MBProgressHUD hideHUDForView:self.view animated:YES];
                if (_cameraSwitch.isOn)
                {
                    [self drawCameraCaptureRect:@"MHRCameraCaptureRect"];
                    _faceLabel.text = FACE_MESSAGE;
                }
                else
                {
                    _fingerLabel.text = FINGER_MESSAGE;
                    _faceLabel.text = @"";
                }
                [_videoCamera start];
            });
        });
    }
}


- (IBAction)switchCamera:(id)sender
{
    if (_cameraSwitch.isOn)
    {
        // front camera - face capturing
        [MHRUtilities setTorchModeOn:NO];
        _faceLabel.text = FACE_MESSAGE;
        _fingerLabel.text = @"";
        [self drawCameraCaptureRect:@"MHRCameraCaptureRect"];
        [_videoCamera stop];
        _videoCamera.defaultAVCaptureDevicePosition = AVCaptureDevicePositionFront;
        [_videoCamera start];
    }
    else
    {
        // back camera - finger capturing
        [MHRUtilities setTorchModeOn:YES];
        _faceLabel.text = @"";
        _fingerLabel.text = FINGER_MESSAGE;
        [self drawCameraCaptureRect:@"MHRWhiteColor"];
        [_videoCamera stop];
        _videoCamera.defaultAVCaptureDevicePosition = AVCaptureDevicePositionBack;
//        [_videoCamera start];
    }
}


- (void)drawCameraCaptureRect:(NSString *)colorKey
{
    int x0 = self.imageView.frame.origin.x;
    int y0 = self.imageView.frame.origin.y;
    int x1 = x0 + self.imageView.frame.size.width;
    int y1 = y0 + self.imageView.frame.size.height;
    int dx = (CAMERA_HEIGHT - IMAGE_HEIGHT)/2;
    int dy = (CAMERA_WIDTH - IMAGE_WIDTH)/2;
    // horizontal lines
    [self.view.layer addSublayer:[MHRUtilities newRectangleLayer:CGRectMake(x0 + dx, y0 + dy, IMAGE_WIDTH, 5) pListKey:colorKey]];
    [self.view.layer addSublayer:[MHRUtilities newRectangleLayer:CGRectMake(x0 + dx, y1 - dy, IMAGE_WIDTH, 5) pListKey:colorKey]];
    // vertical lines
    [self.view.layer addSublayer:[MHRUtilities newRectangleLayer:CGRectMake(x0 + dx, y0 + dy, 5, IMAGE_HEIGHT) pListKey:colorKey]];
    [self.view.layer addSublayer:[MHRUtilities newRectangleLayer:CGRectMake(x1 - dx, y0 + dy, 5, IMAGE_HEIGHT+5) pListKey:colorKey]];
}


#pragma - Protocol CvVideoCameraDelegate

- (void)processImage:(Mat &)image
{
    if (isCapturing && (&_videoWriter != nullptr) && _videoWriter.isOpened())
    {
        ++_nFrames;
        Mat new_image = image(cropArea);
        frameToFile(new_image, [[_outPath stringByAppendingString:@"test_frame_frome_camera.jpg"] UTF8String]);
        cvtColor(new_image, new_image, CV_BGRA2BGR);
        _videoWriter << new_image;
//        printf("image after resize = (%d, %d)\n", new_image.rows, new_image.cols);
    }
}


#pragma - Test Image/Video
//- (void)updateImageView:(NSInteger)index vid:(vector<Mat>)vid
//{
//    if (index >= vid.size())
//        return;
//    self.imageView.image = [UIImageCVMatConverter UIImageFromCVMat:vid[index]];
//    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(1.0 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
//        [self updateImageView:index+1 vid:vid];
//    });
//}

@end
