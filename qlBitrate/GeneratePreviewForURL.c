//
//  GeneratePreviewForURL.c
//  qlBitRate
//
//  Created by @jordansaints on 12/12/13.
//  Copyright (c) 2013 Jordan Saints. All rights reserved.
//  http://www.jordansaints.com/
//  https://github.com/jordansaints
//

#include <CoreFoundation/CoreFoundation.h>
#include <CoreServices/CoreServices.h>
#include <QuickLook/QuickLook.h>


OSStatus GeneratePreviewForURL(void *thisInterface, QLPreviewRequestRef preview, CFURLRef url, CFStringRef contentTypeUTI, CFDictionaryRef options);
void CancelPreviewGeneration(void *thisInterface, QLPreviewRequestRef preview);


// 
// Generate a preview for the given MP3 file
// Currently only retreiving the CFNumber kMDItemAudioBitRate = the audio bit rate
//
// Possible other values to retreive and display in the future:
//   - filesize
//   - CFNumber kMDItemTempo = a float val that specifies the beats per minute (BPM) of the music contained in the audio file
//
OSStatus GeneratePreviewForURL(void *thisInterface, QLPreviewRequestRef preview, CFURLRef url, CFStringRef contentTypeUTI, CFDictionaryRef options)
{
    // Get metadata of source MP3
    MDItemRef metadata = MDItemCreateWithURL(NULL, url);
    if (!metadata)
    {
        QLPreviewRequestSetURLRepresentation(preview, url, contentTypeUTI, NULL);
        return -1;
    }

    // Retreive audio bit rate attribute from metadata
    CFNumberRef audioBitRate = MDItemCopyAttribute(metadata, kMDItemAudioBitRate);
    if (!audioBitRate)
    {
        QLPreviewRequestSetURLRepresentation(preview, url, contentTypeUTI, NULL);
        return -1;
    }
    
    CFRelease(metadata);
    
    // Extract actual bit rate value (in bits/second)
    int bitRate = 0;
    CFNumberGetValue(audioBitRate, kCFNumberIntType, &bitRate);
    
    CFRelease(audioBitRate);
    
    // Want to convert to display value in kilobits/seconds (kbps)
    bitRate = bitRate/1000;
    
    // Original filename
    CFStringRef filename = CFURLCopyLastPathComponent(url);

    // Build output to display
    CFStringRef keys[1] = {kQLPreviewPropertyDisplayNameKey};
    CFStringRef values[1] = {CFStringCreateWithFormat(kCFAllocatorDefault, NULL, CFSTR("%i Kbps - %@"), bitRate, filename)};
    CFDictionaryRef properties = CFDictionaryCreate(kCFAllocatorDefault, (const void**)keys, (const void**)values, 1, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    QLPreviewRequestSetURLRepresentation(preview, url, contentTypeUTI, properties);
    
    CFRelease(values[0]);
    CFRelease(properties);
    
    // Woohoo!
    return noErr;
}

void CancelPreviewGeneration(void *thisInterface, QLPreviewRequestRef preview)
{
    // Not implemented
}
