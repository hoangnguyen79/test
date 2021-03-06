//
//  hb_counter_pda.cpp
//  MisfitHeartRate
//
//  Created by Thanh Le on 7/2/14.
//  Copyright (c) 2014 misfit. All rights reserved.
//

#include "hb_counter_pda.h"


namespace MHR {
    vector<int> hb_counter_pda(vector<double> temporal_mean, double fr, int firstSample, int window_size,
                       double overlap_ratio, double minPeakDistance, double threshold, hrDebug& debug)
    {
        //Perform peak counting for each window
        int windowStart = firstSample - 1;
        bool isFirstSegment = true;
        vector<pair<double, int>> heartBeats;
        vector<double> heartRates;
        while(windowStart < (int)temporal_mean.size() - 1) {
            
            //Window to perform peak-couting in
            vector<double> segment;
            vector<double> max_peak_strengths, min_peak_strengths;
            vector<int> max_peak_locs, min_peak_locs;
            int segment_length;
            
            int windowEnd = min(windowStart + window_size, (int)temporal_mean.size());
            for(int i = windowStart; i < windowEnd; ++i)
                segment.push_back(temporal_mean[i]);
            
            //Count the number of peaks in this window
            findpeaks(segment, minPeakDistance, threshold, max_peak_strengths, max_peak_locs);
            
            //Define the segment length
            // a. Shine-step-counting style
            if(max_peak_locs.empty()){
                segment_length = (int)segment.size();
            }else{
                for(int i=0; i<(int) segment.size(); ++i) segment[i]=-segment[i];
                findpeaks(segment, minPeakDistance, threshold, min_peak_strengths, min_peak_locs);
                if(min_peak_locs.empty()){
                    segment_length = round((*max_element(max_peak_locs.begin(), max_peak_locs.end()) + window_size)/2.0 + 1); //round
                    segment_length = min(segment_length, (int)segment.size());
                }else{
                    segment_length = round((*max_element(max_peak_locs.begin(), max_peak_locs.end())
                                      + *max_element(min_peak_locs.begin(), min_peak_locs.end()))/2.0 + 1) ; //round
                }
                for(int i=0; i<(int) segment.size(); ++i) segment[i]=-segment[i];
            }
            
            // b. Equal_step progression
            // segment_length = window_size;
            
            // Record all beats in the window, even if there are duplicates
            for(int i=0; i<(int) max_peak_locs.size(); ++i)
                heartBeats.push_back(pair<double, int> (max_peak_strengths[i], max_peak_locs[i] + windowStart));
        
            // Calculate the HR for this window
            int windowUpdate = int((1-overlap_ratio)*segment_length+0.5+1e-9);
            if (isFirstSegment) {
                for (int i = 0; i < windowStart; ++i)
                    heartRates.push_back(0);
                isFirstSegment = false;
            }
            
            int count = 0;
            for (int i = 0, sz = (int)segment.size(); i < sz; ++i)
                if (segment[i] > NaN && segment[i] < INFINITY)
                    ++count;
            double rate = (double) max_peak_locs.size() / count * fr;
        
            for(int i = windowStart; i < windowStart+windowUpdate; ++i)
                heartRates.push_back(rate);
            
            windowStart = windowStart + windowUpdate;
        }
        
        //Prune the beats counted to include only unique ones
        heartBeats = unique_stable(heartBeats);
        
        //Calc the avg HR for the whole stream
        
        double avg_hr=0;
        if(!heartBeats.empty()){
            //avg_hr = round((double)heartBeats.size() / ((double)heartRates.size() - firstSample) * fr * 60);
            int cnt=0;
            for(int i=firstSample-1; i<(int)temporal_mean.size(); ++i)
                if(temporal_mean[i] != NaN) ++cnt;
            if(cnt==0) avg_hr = 0;
            else
                avg_hr = round((double)heartBeats.size() / cnt * fr * 60);
        };
        
        debug.avg_hr = avg_hr;
        debug.heartBeats = heartBeats;
        debug.heartRates = heartRates;
        
        vector<int> locations;
        for (int i = 0, sz = (int)heartBeats.size(); i < sz; ++i)
            locations.push_back(heartBeats[i].second);
        sort(locations.begin(), locations.end());
        
        return locations;
    }
}