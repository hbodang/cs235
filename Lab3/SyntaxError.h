//
//  SyntaxError.h
//  Lab3
//
//  Created by Haley Dennis on 2/23/17.
//  Copyright © 2017 Haley Dennis. All rights reserved.
//

#ifndef SyntaxError_h
#define SyntaxError_h

class SyntaxError : public std::invalid_argument
{
public:
    SyntaxError(std::string msg) : std::invalid_argument(msg) {}
};

#endif /* SyntaxError_h */
