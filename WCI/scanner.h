//
//  scanner.h
//  WCI
//
//  Created by cameron belt on 8/19/17.
//  Copyright © 2017 Cameron Belt. All rights reserved.
//

#ifndef scanner_h
#define scanner_h

#include "stdafx.h"
#include <stdio.h>
#include "misc.h"
#include "buffer.h"
#include "token.h"

class TScanner {
protected:
    TWordToken wordToken;
    TNumberToken numberToken;
    TStringToken stringToken;
    TSpecialToken specialToken;
    TEOFToken eofToken;
    TErrorToken errorToken;
    
public:
    virtual ~TScanner(void){}
    virtual TToken *Get(void) = 0;
};

class TTextScanner : public TScanner {
    TTextInBuffer *const pTextInBuffer;
    void SkipWhiteSpace(void);
    
public:
    TTextScanner(TTextInBuffer *pBuffer);
    virtual ~TTextScanner(void) {delete pTextInBuffer;}
    virtual TToken *Get(void);
};

#endif /* scanner_hpp */
