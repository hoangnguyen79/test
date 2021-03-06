% magnify_euler_pyr(vidFile, outDir, alpha, 
%                                      level, freq_band_low_end, freq_band_high_end, samplingRate, 
%                                      chromAttenuation)
% Based on code by Hao-yu Wu, Michael Rubinstein, Eugene Shih (June 2012)
%
% Spatial Filtering: Gaussian blur and down sample
% Temporal Filtering: 15-tap FIR
% 
%
function magnify_phase_pyr_allband_frames(vidFolder, ...
											alpha, level, ...
											freq_band_low_end, freq_band_high_end, ...
											chroma_magnifier, ...
											channels_to_process, ...
											new_fr, new_size, ...
											in_filetype, out_filetype)
    %Load constants
    initialiser;
										   
    disp('Loading the frames...')									   
    % Read video
    if strcmpi(channels_to_process, 'all')
    	channels_to_process = 1 : 3;
    end
    
	vid = frame_loader(vidFolder, frame_size, channels_to_process, in_filetype); % Double array
	
	global full_fr full_vidHeight full_vidWidth
	full_vidHeight = size(vid, 1);
	full_vidWidth = size(vid, 2);
	if exist([vidFolder '/vid_specs.txt'])
		full_fr = textscan(fopen([vidFolder '/vid_specs.txt']), '%d, %d');
		full_fr = double(full_fr{2});
	else
		full_fr = size(vid, 4) / recordingTime; %Double
	end
	
	
	% Re-sample & resize the video
	vid = frame_interpolater(vid, new_fr, new_size);

	% Extract video info
	vidHeight = size(vid, 1);
	vidWidth = size(vid, 2);
	len = size(vid, 4); %Int
	fr = len / recordingTime; %Double
	    
	samplingRate = fr;
 	
 	% Update the maximum level
	[~, ~, lofilt, ~, ~, ~] = eval('sp1Filters'); % sp1Filters is the default filter used here. Unlikely to change though
 	level = min(level, maxPyrHt([vidHeight, vidWidth], size(lofilt,1)));
	
    % Define the indices of the frames to be processed
    startIndex = startFrame;
    
    if endFrame > 0
    	endIndex = endFrame;
    else
    	endIndex = len + endFrame;
    end
    disp('Finished')
    
    %% ================= Core part of the algo described in literature
    %---- Decompose the frame stream into the pyramids
    disp('Spatial filtering...')
    [pyramids, pind] = func_build_pyramid(vid, startIndex, endIndex, level); % PxCxT array where P: each pixel in the whole pyramid for 1 frame, C: colour channels, T: time
    
    % Convert the pyramids from cartesian to polar representation
    [pyramids, band_pairs, band_indices] = cart2polarPyr(pyramids, pind);
    disp('Finished')
    
    clearvars 'vid'
    
    %---- Temporal filtering to remove DC and noise
    % This is performed on the phases
    disp('Temporal filtering...')
    
    % Create phase-only pyramids (where mag should be, it is 0)
    mask = zeros(size(pyramids));
    for band_pair = 1 : size(band_pairs, 1)
    	mask(band_indices{band_pairs(band_pair, 2)}, :, :) = 1;
    end
    %mag_pyrs = (1 - mask) .* pyramids;
    phase_pyrs = mask .* pyramids;
    clearvars 'mask'
    
    filtered_phase_pyrs = ideal_bandpassing(phase_pyrs, length(size(phase_pyrs)), freq_band_low_end, freq_band_high_end, samplingRate); % PxCxT
    if length(channels_to_process) == 1
        filtered_phase_pyrs = permute(filtered_phase_pyrs, [2 3 1]);
    end
    
    disp('Finished')
    
    clearvars 'phase_pyrs'
    
    % Amplify
    filtered_phase_pyrs = filtered_phase_pyrs * alpha;
    
    % Weigh the phase by the magnitude
    % Not implemented yet
        
    % Add the amplified phases with the original pyramids
    filtered_pyramids = pyramids + filtered_phase_pyrs;
	
	clearvars 'pyramids'
    clearvars 'filtered_phase_pyrs'
	
    % Convert the pyramids from polar back to cartesian representation
    [filtered_pyramids, ~, ~] = polar2cartPyr(filtered_pyramids, pind);
    
    %-----------------
    
    
	% Reconstruct the frame stream from the pyramids and write out
    disp('Rendering...')
    
    if exist(fullfile(vidFolder, 'out'))
    	rmdir(fullfile(vidFolder, 'out'), 's');
    end
    mkdir(fullfile(vidFolder, 'out'));
    
    k = 0;
    for i = startIndex : endIndex
        k = k + 1;
        
        if k <= size(filtered_pyramids, 1)
			% Reconstruct the frame from its pyramid
			filtered_pyramid = filtered_pyramids(:, :, k);
			
			processed_frame = [];
			if strcmpi(pyramid_style, 'steerable')
				for chan = 1 : size(filtered_pyramid, 2)
					processed_frame(:, :, chan) = func_recon_pyr(filtered_pyramid(:, chan), pind, filter_file);
				end
			else
				for chan = 1 : size(filtered_pyramid, 2)
					processed_frame(:, :, chan) = func_recon_pyr(filtered_pyramid(:, chan), pind);
				end
            end
			
			% Format the image to the right size
			processed_frame = imresize(processed_frame, [vidHeight vidWidth]); %Bicubic interpolation
		
			% Normalise the resultant frame
			for chan = 1 : size(processed_frame, 3)
				temp = processed_frame(:, :, chan);
				temp_range = max(temp(:)) - min(temp(:));
				processed_frame(:, :, chan) = (temp - min(temp(:))) / temp_range;
			end
			
			% Clip the values of the frame by 0 and 1
			processed_frame(processed_frame > 1) = 1;
			processed_frame(processed_frame < 0) = 0;
			
			% Write the frame into the video as unsigned 8-bit integer array
			filename = fullfile(vidFolder, 'out', ...
								[num2str(k)...
								'-idl-' num2str(freq_band_low_end) ...
								'-' num2str(freq_band_high_end) ...
								'-alp-' num2str(alpha) ...
								'-lvl-' num2str(level) ...
								'-chAtn-' num2str(chroma_magnifier)]);
			
			processed_frame = im2uint8(processed_frame);
			switch out_filetype
				case 'png'
					imwrite(processed_frame, [filename '.png'], 'png');
                case 'mat'
					save([filename '.mat'], 'processed_frame');
			end
		else
			break;
		end
    end
    
    if exist([vidFolder '/vid_specs.txt'])
    	copyfile([vidFolder '/vid_specs.txt'], fullfile(vidFolder, 'out'));
	end
	
    disp('Finished')
end
