//
//  GenerateThumbnailForURL.c
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

OSStatus GenerateThumbnailForURL(void *thisInterface, QLThumbnailRequestRef thumbnail, CFURLRef url, CFStringRef contentTypeUTI, CFDictionaryRef options, CGSize maxSize);
void CancelThumbnailGeneration(void *thisInterface, QLThumbnailRequestRef thumbnail);


// Generate a thumbnail for file (left as default thumbnail option)
OSStatus GenerateThumbnailForURL(void *thisInterface, QLThumbnailRequestRef thumbnail, CFURLRef url, CFStringRef contentTypeUTI, CFDictionaryRef options, CGSize maxSize)
{
    QLThumbnailRequestSetImageAtURL(thumbnail, url, NULL);
    return noErr;
}

void CancelThumbnailGeneration(void *thisInterface, QLThumbnailRequestRef thumbnail)
{
    // Not implemented
}
