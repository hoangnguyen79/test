//
//  MHRResultViewController.m
//  MisfitHeartRate
//
//  Created by Bao Nguyen on 7/8/14.
//  Copyright (c) 2014 misfit. All rights reserved.
//

#import "MHRResultViewController.hpp"

@interface MHRResultViewController ()

@property (weak, nonatomic) IBOutlet UILabel *autocorrLabel;
@property (weak, nonatomic) IBOutlet UILabel *pdaLabel;

@end


@implementation MHRResultViewController

@synthesize autocorrResult = _autocorrResult;
@synthesize pdaResult = _pdaResult;


- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initializationa
    }
    return self;
}


- (void)viewDidLoad
{
    [super viewDidLoad];
    self.pdaLabel.hidden = YES;
    self.autocorrLabel.text = [NSString stringWithFormat:@"%.0f", _autocorrResult];
    self.pdaLabel.text = [NSString stringWithFormat:@"%.0f", _pdaResult];
    if (_autocorrResult < 0 || _pdaResult < 0) {
        NSString *message = [NSString stringWithFormat:@"Recording was stopped too early! Try recording again for at least %d seconds.", MHR::_minVidLength];
        [UIAlertView alertViewWithTitle:@"Error" message:message cancelButtonTitle:@"OK"];
    }
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
