//
//  error.cpp
//  WCI
//
//  Created by cameron belt on 8/9/17.
//  Copyright © 2017 Cameron Belt. All rights reserved.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include "error.h"
#include <string>

using namespace std;

int errorCount = 0;

static string abortMsg[] = {
     "NULL",
    "Invalid command line arguments",
    "Failed to open source file",
    "Failed to open intermediate form file",
    "Failed to open assembly file",
    "Too many syntax errors",
    "Stack overflow",
    "Code segment overflow",
    "Nesting too deep",
    "Runtime error",
    "Unimplemented feature",
};

void AbortTranslation(TAbortCode ac){
    cerr << "*** Fate translator error: " << abortMsg[-ac]  << endl;
    exit(ac);
}
