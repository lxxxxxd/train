//
//  status.h
//  train
//
//  Created by xiaodong liu on 2019/8/9.
//  Copyright © 2019 xiaodong liu. All rights reserved.
//

#ifndef status_h
#define status_h

typedef enum {
    SUCCESS,
    ERROR_START = -10,
    NOT_FOUND_ELEM_ERROR = ERROR_START,  //
    NONE_POINTOR_ERROR,
    OUT_RNAGE_ERROR,
    OVER_FLOW_ERROR,
}Status;

#endif /* status_h */
