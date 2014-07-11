//
//  hrDebug.cpp
//  MisfitHeartRate
//
//  Created by Thanh Le on 7/2/14.
//  Copyright (c) 2014 misfit. All rights reserved.
//

#include "hrDebug.h"


namespace MHR {
    void testMathFunctions()
    {
//        int sizeArr[] = {30, 40, 100};
//        Mat img = Mat(3, sizeArr, CV_64F, CvScalar(0));
//        double v = 0, delta = 1;
//        for(int i=0; i<100; ++i){
//            if(v==10){
//                delta=-1;
//            }else if(v==-10){
//                delta=1;
//            }
//            v+=delta;
//            for(int x=0; x<30; ++x) for(int y=0; y<40; ++y) img.at<double>(x,y,i)=v;
//        }
//        Mat debugImg;
//        vector<double> ans = frames2signal(img, "mode-balance", 30, 0, debugImg);
//        for(int i=0; i<(int) ans.size(); ++i) cout<<ans[i]<<' '; cout<<endl;

        
//        vector<double> arr;
//        for(int i=0; i<100; ++i){
//        arr.push_back(1.0*(rand()%10000)/(rand()%100));
//        }
//        cout<<"[";
//        for(int i=0; i<100-1;++i) cout<<arr[i]<<", "; cout<<arr[99]<<"]"<<endl;
//        arr=low_pass_filter(arr);
//        cout<<"[";
//        for(int i=0; i<100-1;++i) cout<<arr[i]<<", "; cout<<arr[99]<<"]"<<endl;

        
//        vector<double>seg1{1, 7, 3, 89, 5, 16, 5};
//        vector<double> seg2{0.1, 1.38, 0.76};
//        vector<double> ans = conv(seg1,seg2);
//        cout<<(int)ans.size()<<endl;
//        for(int i=0; i<(int)ans.size(); ++i) cout<<ans[i]<<' '; cout<<endl;
 

//        vector<double> arr;
//        srand(time(NULL));
//        for(int i=1; i<=100; ++i) arr.push_back(i);
//        for(int i=1; i<=100; ++i){
//        double per=(rand()%10001)/100.0;
//        cout<<i<<' '<<per<<' '<<prctile(arr, per)<<' '<<invprctile(arr, prctile(arr,per))<<endl;
//        }
 

//        invprctile checking
//        vector<double> arr {5,1,3,2.2,3.1,5.6,10};
//        cout<<invprctile(arr, 10)<<endl;
//        cout<<invprctile(arr, 0)<<endl;
//        cout<<invprctile(arr, 1)<<endl;


//        srand(time(NULL));
//        vector<double> data {0,2,9,2,5,8,7,3,1,9,4,3,5,8,10,0,1,2,9,5,10};
//        vector<int> counts;
//        vector<double> centers;
//        hist(data, 10, counts, centers);
//        cout<<counts.size()<<endl;
//        for(int i=0; i<(int) counts.size(); ++i) cout<<centers[i]<<' '<<counts[i]<<endl;


//        vector<double> segment;
//        for(double x=0; x<=100; x+=0.01) segment.push_back(sin(x*acos(-1)));
//        vector<double> strengths;
//        vector<int> locs;
//        findpeaks(segment, 300, 0, strengths, locs);
//        printf("%d\n",(int)strengths.size());
//        for(int i=0; i<strengths.size(); ++i)
//         printf("%lf %d\n",strengths[i], locs[i]);
    }
    
    
//    void test_rgb2ntsc() {
//        int nRow = 10, nCol = 10;
//        double test_array_0[] = {
//            0.8147, 0.1576, 0.6557, 0.7060, 0.4387, 0.2760, 0.7513, 0.8407, 0.3517, 0.0759,
//            0.9058, 0.9706, 0.0357, 0.0318, 0.3816, 0.6797, 0.2551, 0.2543, 0.8308, 0.0540,
//            0.1270, 0.9572, 0.8491, 0.2769, 0.7655, 0.6551, 0.5060, 0.8143, 0.5853, 0.5308,
//            0.9134, 0.4854, 0.9340, 0.0462, 0.7952, 0.1626, 0.6991, 0.2435, 0.5497, 0.7792,
//            0.6324, 0.8003, 0.6787, 0.0971, 0.1869, 0.1190, 0.8909, 0.9293, 0.9172, 0.9340,
//            0.0975, 0.1419, 0.7577, 0.8235, 0.4898, 0.4984, 0.9593, 0.3500, 0.2858, 0.1299,
//            0.2785, 0.4218, 0.7431, 0.6948, 0.4456, 0.9597, 0.5472, 0.1966, 0.7572, 0.5688,
//            0.5469, 0.9157, 0.3922, 0.3171, 0.6463, 0.3404, 0.1386, 0.2511, 0.7537, 0.4694,
//            0.9575, 0.7922, 0.6555, 0.9502, 0.7094, 0.5853, 0.1493, 0.6160, 0.3804, 0.0119,
//            0.9649, 0.9595, 0.1712, 0.0344, 0.7547, 0.2238, 0.2575, 0.4733, 0.5678, 0.3371};
//        
//        double test_array_1[] = {
//            0.1622, 0.4505, 0.1067, 0.4314, 0.8530, 0.4173, 0.7803, 0.2348, 0.5470, 0.9294,
//            0.7943, 0.0838, 0.9619, 0.9106, 0.6221, 0.0497, 0.3897, 0.3532, 0.2963, 0.7757,
//            0.3112, 0.2290, 0.0046, 0.1818, 0.3510, 0.9027, 0.2417, 0.8212, 0.7447, 0.4868,
//            0.5285, 0.9133, 0.7749, 0.2638, 0.5132, 0.9448, 0.4039, 0.0154, 0.1890, 0.4359,
//            0.1656, 0.1524, 0.8173, 0.1455, 0.4018, 0.4909, 0.0965, 0.0430, 0.6868, 0.4468,
//            0.6020, 0.8258, 0.8687, 0.1361, 0.0760, 0.4893, 0.1320, 0.1690, 0.1835, 0.3063,
//            0.2630, 0.5383, 0.0844, 0.8693, 0.2399, 0.3377, 0.9421, 0.6491, 0.3685, 0.5085,
//            0.6541, 0.9961, 0.3998, 0.5797, 0.1233, 0.9001, 0.9561, 0.7317, 0.6256, 0.5108,
//            0.6892, 0.0782, 0.2599, 0.5499, 0.1839, 0.3692, 0.5752, 0.6477, 0.7802, 0.8176,
//            0.7482, 0.4427, 0.8001, 0.1450, 0.2400, 0.1112, 0.0598, 0.4509, 0.0811, 0.7948};
//
//        double test_array_2[] = {
//            0.6443, 0.2077, 0.3111, 0.5949, 0.0855, 0.9631, 0.0377, 0.1068, 0.0305, 0.1829,
//            0.3786, 0.3012, 0.9234, 0.2622, 0.2625, 0.5468, 0.8852, 0.6538, 0.7441, 0.2399,
//            0.8116, 0.4709, 0.4302, 0.6028, 0.8010, 0.5211, 0.9133, 0.4942, 0.5000, 0.8865,
//            0.5328, 0.2305, 0.1848, 0.7112, 0.0292, 0.2316, 0.7962, 0.7791, 0.4799, 0.0287,
//            0.3507, 0.8443, 0.9049, 0.2217, 0.9289, 0.4889, 0.0987, 0.7150, 0.9047, 0.4899,
//            0.9390, 0.1948, 0.9797, 0.1174, 0.7303, 0.6241, 0.2619, 0.9037, 0.6099, 0.1679,
//            0.8759, 0.2259, 0.4389, 0.2967, 0.4886, 0.6791, 0.3354, 0.8909, 0.6177, 0.9787,
//            0.5502, 0.1707, 0.1111, 0.3188, 0.5785, 0.3955, 0.6797, 0.3342, 0.8594, 0.7127,
//            0.6225, 0.2277, 0.2581, 0.4242, 0.2373, 0.3674, 0.1366, 0.6987, 0.8055, 0.5005,
//            0.5870, 0.4357, 0.4087, 0.5079, 0.4588, 0.9880, 0.7212, 0.1978, 0.5767, 0.4711};
//        
//        Mat input = Mat::zeros(nRow, nCol, CV_64FC3);
//        for (int i = 0; i < nRow; ++i)
//            for (int j = 0; j < nCol; ++j) {
//                input.at<Vec3d>(i, j)[0] = test_array_0[i*nCol + j];
//                input.at<Vec3d>(i, j)[1] = test_array_1[i*nCol + j];
//                input.at<Vec3d>(i, j)[2] = test_array_2[i*nCol + j];
//            }
//        printf("Input mat:\n");
//        for (int channel = 0; channel < 3; ++channel) {
//            for (int i = 0; i < input.rows; ++i) {
//                for (int j = 0; j < input.cols; ++j)
//                    printf("%lf, ", input.at<Vec3d>(i, j)[channel]);
//                printf("\n");
//            }
//            printf("\n\n\n\n\n");
//        }
//        
//        Mat output;
//        rgb2ntsc(input, output);
//        printf("Output mat:\n");
//        for (int channel = 0; channel < 3; ++channel) {
//            for (int i = 0; i < output.rows; ++i) {
//                for (int j = 0; j < output.cols; ++j)
//                    printf("%lf, ", output.at<Vec3d>(i, j)[channel]);
//                printf("\n");
//            }
//            printf("\n\n\n\n\n");
//        }
//        
//        ntsc2rgb(output, input);
//        printf("NTSC mat:\n\n");
//        for (int channel = 0; channel < 3; ++channel) {
//            for (int i = 0; i < input.rows; ++i) {
//                for (int j = 0; j < input.cols; ++j)
//                    printf("%lf, ", input.at<Vec3d>(i, j)[channel]);
//                printf("\n");
//            }
//            printf("\n\n\n\n\n");
//        }
//    }
    
        
    void test_ideal_bandpassing() {
        int nTime = 100, nRow = 10, nCol = 1;
        double samplingRate = 20;
        double wl = 2;
        double wh = 7;
        double test_array[] = {0.0579, 0.1376, 0.2215, 0.3865, 0.6278, 0.4249, 0.9053, 0.8134, 0.9178, 0.5872, 0.0441, 0.4241, 0.7058, 0.6030, 0.4467, 0.5216, 0.4711, 0.7876, 0.4297, 0.1548, 0.8129, 0.7646, 0.5968, 0.5603, 0.8111, 0.8403, 0.9105, 0.1243, 0.0797, 0.4455, 0.4121, 0.5244, 0.5863, 0.8458, 0.1448, 0.6250, 0.3280, 0.1574, 0.5721, 0.5376, 0.3842, 0.7545, 0.9685, 0.2848, 0.9748, 0.2552, 0.6911, 0.4150, 0.8318, 0.4619, 0.5231, 0.1698, 0.5817, 0.6633, 0.8338, 0.9047, 0.0174, 0.6873, 0.3474, 0.8341, 0.8921, 0.6727, 0.0998, 0.6023, 0.3401, 0.7673, 0.5123, 0.6577, 0.7799, 0.9962, 0.4059, 0.6187, 0.1666, 0.6565, 0.6162, 0.5627, 0.3318, 0.6800, 0.7083, 0.9722, 0.6044, 0.0068, 0.1021, 0.3099, 0.3038, 0.8972, 0.3361, 0.0094, 0.5909, 0.7459, 0.0948, 0.7402, 0.1462, 0.3316, 0.0892, 0.3681, 0.9533, 0.1286, 0.3770, 0.2000, 0.3360, 0.9917, 0.6716, 0.1882, 0.5215, 0.3377, 0.7505, 0.7639, 0.3938, 0.0363, 0.1448, 0.1282, 0.6399, 0.1007, 0.8253, 0.6189, 0.3339, 0.8419, 0.4283, 0.1886, 0.2449, 0.3606, 0.3724, 0.2866, 0.7639, 0.0869, 0.6328, 0.7469, 0.4230, 0.5775, 0.3790, 0.1911, 0.1629, 0.3548, 0.9476, 0.3755, 0.4155, 0.9445, 0.2189, 0.6283, 0.2703, 0.7144, 0.3895, 0.5358, 0.3335, 0.1874, 0.5765, 0.9197, 0.4968, 0.3648, 0.2156, 0.1779, 0.8000, 0.9908, 0.3897, 0.8105, 0.9595, 0.2231, 0.0399, 0.6366, 0.6337, 0.9868, 0.3998, 0.0282, 0.1504, 0.7232, 0.6158, 0.5098, 0.5648, 0.8913, 0.7997, 0.0170, 0.7551, 0.7095, 0.3337, 0.6747, 0.1506, 0.7877, 0.0491, 0.2535, 0.2085, 0.0398, 0.2952, 0.9052, 0.5537, 0.9140, 0.8383, 0.5225, 0.8723, 0.2864, 0.8963, 0.8043, 0.6400, 0.8658, 0.5503, 0.8210, 0.7262, 0.6174, 0.8600, 0.1254, 0.7457, 0.8598, 0.8851, 0.1192, 0.1604, 0.5487, 0.1088, 0.5582, 0.3383, 0.5286, 0.5364, 0.5663, 0.2096, 0.9553, 0.1171, 0.0155, 0.1614, 0.7310, 0.9740, 0.8208, 0.9700, 0.7541, 0.4804, 0.4409, 0.3986, 0.0947, 0.2970, 0.0634, 0.9548, 0.2998, 0.5649, 0.5195, 0.1130, 0.8758, 0.8314, 0.5148, 0.4236, 0.4928, 0.9886, 0.7877, 0.2177, 0.5859, 0.1324, 0.8650, 0.1850, 0.9525, 0.5284, 0.2299, 0.1577, 0.4370, 0.8578, 0.1907, 0.0640, 0.3552, 0.5008, 0.8431, 0.2751, 0.3374, 0.0029, 0.5505, 0.8620, 0.5034, 0.0793, 0.6311, 0.1263, 0.9350, 0.8280, 0.5516, 0.2482, 0.9861, 0.3133, 0.0509, 0.6270, 0.8645, 0.8646, 0.9734, 0.7928, 0.7437, 0.3463, 0.6898, 0.3270, 0.0561, 0.4113, 0.0210, 0.7666, 0.3725, 0.2737, 0.4123, 0.2333, 0.9701, 0.8400, 0.3352, 0.6386, 0.0768, 0.5644, 0.3209, 0.6157, 0.5076, 0.7559, 0.0960, 0.4925, 0.6309, 0.8566, 0.3767, 0.3896, 0.7832, 0.1016, 0.1290, 0.2259, 0.8981, 0.0519, 0.8920, 0.7636, 0.1492, 0.4901, 0.2122, 0.6700, 0.2148, 0.4484, 0.0584, 0.7780, 0.6734, 0.9762, 0.0341, 0.8869, 0.9592, 0.3474, 0.2928, 0.2594, 0.1233, 0.4267, 0.6853, 0.7815, 0.7822, 0.9050, 0.9302, 0.6695, 0.4500, 0.3458, 0.6307, 0.2800, 0.6957, 0.9356, 0.3272, 0.4984, 0.3657, 0.2953, 0.2403, 0.9030, 0.3701, 0.3335, 0.7998, 0.7392, 0.8175, 0.5292, 0.3449, 0.6804, 0.2633, 0.0127, 0.3196, 0.3669, 0.6606, 0.2536, 0.1736, 0.9097, 0.6927, 0.3938, 0.8916, 0.1322, 0.7957, 0.7948, 0.5199, 0.7193, 0.6761, 0.5786, 0.7166, 0.3918, 0.5861, 0.3881, 0.3017, 0.0387, 0.3317, 0.6935, 0.8756, 0.7758, 0.8003, 0.2070, 0.9387, 0.8406, 0.6075, 0.7267, 0.9342, 0.7733, 0.7572, 0.6614, 0.5937, 0.7245, 0.6181, 0.2133, 0.4620, 0.8727, 0.2465, 0.7472, 0.2296, 0.4697, 0.0972, 0.8193, 0.2507, 0.9352, 0.2926, 0.2858, 0.5112, 0.3184, 0.3589, 0.2198, 0.5595, 0.9265, 0.1025, 0.9698, 0.8324, 0.6568, 0.7403, 0.5104, 0.3632, 0.6026, 0.0431, 0.5141, 0.5464, 0.3753, 0.5705, 0.2319, 0.2542, 0.7731, 0.2674, 0.1843, 0.7576, 0.1931, 0.4426, 0.9849, 0.0705, 0.6220, 0.8456, 0.5728, 0.3373, 0.1975, 0.6596, 0.6029, 0.6915, 0.1221, 0.2663, 0.0751, 0.5382, 0.9539, 0.0870, 0.8620, 0.5995, 0.1982, 0.7594, 0.7610, 0.1709, 0.9668, 0.9101, 0.1716, 0.4516, 0.1256, 0.2270, 0.4104, 0.3994, 0.5794, 0.5603, 0.6100, 0.3507, 0.9072, 0.4547, 0.6456, 0.7137, 0.8531, 0.5674, 0.6212, 0.2021, 0.3837, 0.9353, 0.7522, 0.0290, 0.4373, 0.7245, 0.4291, 0.2056, 0.4899, 0.4924, 0.0306, 0.9277, 0.2862, 0.6371, 0.6126, 0.3442, 0.9257, 0.9435, 0.2205, 0.7294, 0.8576, 0.5877, 0.6274, 0.0595, 0.7375, 0.0328, 0.3731, 0.5128, 0.1441, 0.9550, 0.6035, 0.1018, 0.4628, 0.1692, 0.3033, 0.8436, 0.6982, 0.2762, 0.6352, 0.7624, 0.8478, 0.3669, 0.1294, 0.6847, 0.0430, 0.7703, 0.5886, 0.2291, 0.8024, 0.0801, 0.5046, 0.2758, 0.5494, 0.5546, 0.8355, 0.5096, 0.1009, 0.9529, 0.6696, 0.9382, 0.0079, 0.2661, 0.9695, 0.0060, 0.3693, 0.7070, 0.4124, 0.6894, 0.4716, 0.9745, 0.9191, 0.2265, 0.4421, 0.2881, 0.6613, 0.7912, 0.9247, 0.7079, 0.9445, 0.6071, 0.4107, 0.0013, 0.5910, 0.3766, 0.8957, 0.3307, 0.0556, 0.6569, 0.5915, 0.9575, 0.7324, 0.8930, 0.1110, 0.1465, 0.2741, 0.9137, 0.3840, 0.7790, 0.2267, 0.3307, 0.1511, 0.4535, 0.1999, 0.0745, 0.9979, 0.5767, 0.2406, 0.5805, 0.6838, 0.9012, 0.8152, 0.5784, 0.1630, 0.4607, 0.8344, 0.2879, 0.2278, 0.5032, 0.3206, 0.0004, 0.9096, 0.3156, 0.0369, 0.3704, 0.7913, 0.2669, 0.3571, 0.8787, 0.7489, 0.4833, 0.7779, 0.9940, 0.2727, 0.8246, 0.6566, 0.8902, 0.9241, 0.3929, 0.9981, 0.1475, 0.7571, 0.9839, 0.2301, 0.5375, 0.5437, 0.3661, 0.5025, 0.2426, 0.2697, 0.3150, 0.4052, 0.9645, 0.3585, 0.8175, 0.3867, 0.1500, 0.8032, 0.2816, 0.9319, 0.1714, 0.7019, 0.6663, 0.1343, 0.4604, 0.8222, 0.9463, 0.3503, 0.9048, 0.6964, 0.5929, 0.5655, 0.7262, 0.9986, 0.0140, 0.5953, 0.6508, 0.4587, 0.7027, 0.0953, 0.6576, 0.5847, 0.3340, 0.5135, 0.0050, 0.7816, 0.9822, 0.9511, 0.8531, 0.2459, 0.3490, 0.3449, 0.5228, 0.3878, 0.1662, 0.9877, 0.1938, 0.1330, 0.3787, 0.9347, 0.0537, 0.7042, 0.2734, 0.2499, 0.3659, 0.7883, 0.8287, 0.0703, 0.6330, 0.4798, 0.0472, 0.1609, 0.7184, 0.3648, 0.7182, 0.8529, 0.4938, 0.7061, 0.0316, 0.8825, 0.0559, 0.0015, 0.7780, 0.3991, 0.1594, 0.4856, 0.5908, 0.9317, 0.9200, 0.7793, 0.0715, 0.5620, 0.0811, 0.9263, 0.2788, 0.8738, 0.0449, 0.1089, 0.4697, 0.0183, 0.0157, 0.5465, 0.2216, 0.4955, 0.6449, 0.3338, 0.5645, 0.6517, 0.5199, 0.7708, 0.9737, 0.5508, 0.2040, 0.6092, 0.2872, 0.2053, 0.6335, 0.1461, 0.7663, 0.6858, 0.7348, 0.6945, 0.6241, 0.0048, 0.3219, 0.4944, 0.4981, 0.6940, 0.3362, 0.8677, 0.7524, 0.9275, 0.7252, 0.5877, 0.1554, 0.0312, 0.0596, 0.6256, 0.6260, 0.5805, 0.0333, 0.9442, 0.8344, 0.7775, 0.3877, 0.8276, 0.5152, 0.0437, 0.3269, 0.6261, 0.1176, 0.9033, 0.0189, 0.6572, 0.8957, 0.2643, 0.0532, 0.7979, 0.3111, 0.1111, 0.2613, 0.6041, 0.2021, 0.5283, 0.8878, 0.6775, 0.8436, 0.9862, 0.6461, 0.2137, 0.8934, 0.9262, 0.4691, 0.8258, 0.3936, 0.7939, 0.5947, 0.4367, 0.4337, 0.0364, 0.9721, 0.1169, 0.3784, 0.9624, 0.6755, 0.6818, 0.6910, 0.3447, 0.1029, 0.4445, 0.9941, 0.3408, 0.3404, 0.3137, 0.2522, 0.6508, 0.6472, 0.0488, 0.2362, 0.3266, 0.3468, 0.0367, 0.0639, 0.7971, 0.9500, 0.2373, 0.6234, 0.2252, 0.9718, 0.2873, 0.2923, 0.5384, 0.7613, 0.2852, 0.6247, 0.4774, 0.9539, 0.5810, 0.6989, 0.4965, 0.1872, 0.7372, 0.4027, 0.0149, 0.2069, 0.9364, 0.1769, 0.6014, 0.6595, 0.1817, 0.7431, 0.1812, 0.6743, 0.0941, 0.1097, 0.2411, 0.4749, 0.2525, 0.3261, 0.9338, 0.7180, 0.4262, 0.5511, 0.3287, 0.5658, 0.2091, 0.8424, 0.6543, 0.0198, 0.9402, 0.1889, 0.0982, 0.0515, 0.3056, 0.2743, 0.2725, 0.4970, 0.0601, 0.5705, 0.5915, 0.4339, 0.3032, 0.3075, 0.0180, 0.0712, 0.7758, 0.7624, 0.9405, 0.0363, 0.0008, 0.0456, 0.7801, 0.9654, 0.1622, 0.1584, 0.3314, 0.1799, 0.0925, 0.2647, 0.9030, 0.6555, 0.5370, 0.9315, 0.4440, 0.0495, 0.6031, 0.6916, 0.3340, 0.1907, 0.6829, 0.7810, 0.7691, 0.3780, 0.7668, 0.6809, 0.1840, 0.9144, 0.6510, 0.4493, 0.0739, 0.8629, 0.6389, 0.6177, 0.6813, 0.7818, 0.0875, 0.1627, 0.5039, 0.7687, 0.9964, 0.7854, 0.8931, 0.5625, 0.7145, 0.8074, 0.3089, 0.4281, 0.5309, 0.6279, 0.3145, 0.4335, 0.0607, 0.8306, 0.4598, 0.2651, 0.2309, 0.0419, 0.3791, 0.3147, 0.8092, 0.3478, 0.1758, 0.9577, 0.9193, 0.8959, 0.9092, 0.2257, 0.7689, 0.2920, 0.4615, 0.0554, 0.4163, 0.0755, 0.9889, 0.6080, 0.9369, 0.6662, 0.2825, 0.0782, 0.5871, 0.8194, 0.7398, 0.8880, 0.9326, 0.0144, 0.0319, 0.8713, 0.6493, 0.1719, 0.4776, 0.1060, 0.8930, 0.5624, 0.4615, 0.3440, 0.5936, 0.3447, 0.9222, 0.7213, 0.5525, 0.0061, 0.0259, 0.1944, 0.9049, 0.5337, 0.0438, 0.0273, 0.3307, 0.0894, 0.1753, 0.2750};
        
        int input_size[] = {nTime, nRow, nCol};
        Mat input(3, input_size, CV_64F);
        for (int i = 0; i < nTime; ++i)
            for (int j = 0; j < nRow; ++j)
                input.at<double>(i, j, 0) = test_array[i*nRow + j];
        
        printf("Input:\n");
        for (int i = 0; i < nTime; ++i) {
            for (int j = 0; j < nRow; ++j)
                    printf("%lf, ", input.at<double>(i, j, 0));
            printf("\n");
        }
        printf("\n\n\n\n\n\n\n");

        Mat output;
        ideal_bandpassing(input, output, wl, wh, samplingRate);
        
        printf("Output mat: dim = %i, rows = %i, cols = %i\n", output.dims, output.rows, output.cols);
        for (int i = 0; i < nTime; ++i) {
            for (int j = 0; j < nRow; ++j)
                printf("%lf, ", output.at<double>(i, j, 0));
            printf("\n");
        }
    }
}