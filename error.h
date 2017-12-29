//
//  error.h
//  WCI
//
//  Created by cameron belt on 8/9/17.
//  Copyright © 2017 Cameron Belt. All rights reserved.
//

#ifndef error_h
#define error_h

extern int errorCount;

enum TAbortCode{
    abortInvalidCommandLineArgs = -1,
    abortSourceFileOpenFailed = -2,
    abortIFormFileOpenFailed = -3,
    abortAssemblyFileOpenFailed = -4,
    abortTooManySyntaxErrors = -5,
    abortStackOverflow = -6,
    abortCodeSegmentOverflow = -7,
    abortNestingTooDeep = -8,
    abortRuntimeError = -9,
    aborUnimplementedFeature = -10,
};

void AbortTranslation(TAbortCode ac);


#endif /* error_h */
