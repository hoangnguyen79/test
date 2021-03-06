% pyramids = build_gPyr(VID_FILE, START_INDEX, END_INDEX, LEVEL)
% 
% Apply Gaussian pyramids decomposition on VID_FILE from START_INDEX to
% END_INDEX and select a specific band indicated by LEVEL
% 
% pyramids: stack of one band of Gaussian pyramids of each frame 
% the first dimension is the time axis
% the second dimension is the y axis of the video
% the third dimension is the x axis of the video
% the forth dimension is the color channel
% 
% Copyright (c) 2011-2012 Massachusetts Institute of Technology, 
% Quanta Research Cambridge, Inc.
%
% Authors: Hao-yu Wu, Michael Rubinstein, Eugene Shih, 
% License: Please refer to the LICENCE file
% Date: June 2012
%
function pyramids = build_gPyr_frames(vid, startIndex, endIndex, level)

	% Extract video info
	vidHeight = size(vid, 1);
	vidWidth = size(vid, 2);
	nChannels = 3;
	
	% firstFrame
	rgbframe = vid(:, :, :, startIndex); %Double
	%frame = rgb2ntsc(rgbframe);
	frame = rgbframe;
	
	% Blur and downsample the frame
	blurred = blurDnClr(frame, level);

	% create pyr stack
	% Note that this stack is actually just a SINGLE level of the pyramids
	pyramids = zeros(endIndex - startIndex + 1, size(blurred, 1), size(blurred, 2), size(blurred, 3));
	
	% The first frame in the stack is saved
	pyramids(1, :, :, :) = blurred;

	k = 1;
	for i = startIndex + 1 : endIndex
		k = k + 1;
		
		% Create a frame from the ith array in the stream
		rgbframe = vid(:, :, :, i);
		%frame = rgb2ntsc(rgbframe);
		frame = rgbframe;
	
		% Blur and downsample the frame
		blurred = blurDnClr(frame, level);
		
		% The kth element in the stack is saved
		% Note that this stack is actually just a SINGLE level of the pyramids
		pyramids(k, :, :, :) = blurred;
	end
end
