% magnify_linear_pyr(vidFile, outDir, alpha, 
%                                      level, freq_band_low_end, freq_band_high_end, samplingRate, 
%                                      chromAttenuation)
% Based on code by Hao-yu Wu, Michael Rubinstein, Eugene Shih (June 2012)
%
% Spatial Filtering: Gaussian blur and down sample
% Temporal Filtering: 15-tap FIR
% 
%
function magnify_linear_pyr_video(vidFile, outDir, ...
											alpha, level, ...
                     						freq_band_low_end, freq_band_high_end, ...
                     						samplingRate, chroma_magnifier)
    %Load constants
    initialiser;
    
    % Get the filename-only part of the full path
    [~, vidName] = fileparts(vidFile);
    
    % Create the output file with full path
    outName = fullfile(outDir,[vidName '-ideal-from-' num2str(freq_band_low_end) ...
									   '-to-' num2str(freq_band_high_end) ...
									   '-alpha-' num2str(alpha) ...
									   '-level-' num2str(level) ...
									   '-chromAtn-' num2str(chroma_magnifier) ...
									   '.avi']);
									   
    % Read video
    vid = VideoReader(vidFile);
    
    % Extract video info
    vidHeight = vid.Height;
    vidWidth = vid.Width;
    fr = vid.FrameRate;
    len = vid.NumberOfFrames;
    nChannels = number_of_channels;
    
	samplingRate = fr;
	level = min(level, floor(log((min(vidHeight, vidWidth) - 1) / (Gpyr_filter_length - 1)) / log(2)));
	
    % Prepare the output video-writer
    vidOut = VideoWriter(outName);
    vidOut.FrameRate = fr;
    open(vidOut)
    
    % Define the indices of the frames to be processed
    startIndex = startFrame;
    
    if endFrame > 0
    	endIndex = endFrame;
    else
    	endIndex = len + endFrame;
    end
    
    %% ================= Core part of the algo described in literature
    % compute Gaussian blur stack
    % This stack actually is just a single level of the pyramid
    disp('Spatial filtering...')
    pyramid = func_build_pyramid(vidFile, startIndex, endIndex, level); % TxMxNxC array
    disp('Finished')
    
    % Temporal filtering
    disp('Temporal filtering...')
    filtered_stack = ideal_bandpassing(pyramid, 1, freq_band_low_end, freq_band_high_end, samplingRate);
    %filtered_stack = filter_bandpassing(pyramid, 1);
    disp('Finished')
    
    %% amplify
    filtered_stack(:, :, :, 1) = filtered_stack(:, :, :, 1) .* alpha;
    filtered_stack(:, :, :, 2) = filtered_stack(:, :, :, 2) .* alpha .* chroma_magnifier;
    filtered_stack(:, :, :, 3) = filtered_stack(:, :, :, 3) .* alpha .* chroma_magnifier;
	%% =================

    %% Render on the input video
    disp('Rendering...')
    
    % Create the placeholder for a single movie-frame (which has to have both cdata & colormap, per Matlab def)
    temp = struct('cdata', zeros(vidHeight, vidWidth, nChannels, 'uint8'),...
    			  'colormap', []);
    
    % output video
    k = 0;
    % Convert each frame from the filtered stream to movie frame
    for i = startIndex : endIndex
        k = k + 1;
        
        if k <= size(filtered_stack, 1)
			% Reconstruct the frame from pyramid stack		
			% by removing the singleton dimensions of the kth filtered array
			% since the filtered stack is just a selected level of the Gaussian pyramid
			filtered = squeeze(filtered_stack(k, :, :, :));
		
			% Format the image to the right size
			filtered = imresize(filtered, [vidHeight vidWidth]); %Bicubic interpolation
		
			% Extract the ith frame in the video stream
			temp.cdata = read(vid, i);
			% Convert the extracted frame to RGB image
			[rgbframe, ~] = frame2im(temp);
			% Convert the RGB image to double-precision image
			rgbframe = im2double(rgbframe);
			% Convert the image from RGB colour-space to NTSC colour-space
			%frame = rgb2ntsc(rgbframe);
			
			frame = rgbframe;
			filtered = ntsc2rgb(filtered);
			% Add the filtered frame to the original frame
			filtered = filtered + frame;
		
			% Convert the colour-space from NTSC back to RGB
			%frame = ntsc2rgb(filtered);
			frame = filtered;
			
			% Clip the values of the frame by 0 and 1
			frame(frame > 1) = 1;
			frame(frame < 0) = 0;
		
			% Write the frame into the video as unsigned 8-bit integer array
			writeVideo(vidOut, im2uint8(frame));
		else
			break;
		end
    end

    disp('Finished')
    close(vidOut);
end
