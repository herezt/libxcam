/*
 * xcam_3a_description.h - 3A description
 *
 *  Copyright (c) 2015 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: Wind Yuan <feng.yuan@intel.com>
 */

#ifndef C_XCAM_3A_DESCRIPTION_H
#define C_XCAM_3A_DESCRIPTION_H

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include <linux/atomisp.h>
#include "xcam_defs.h"
#include "xcam_params.h"

XCAM_BEGIN_DECLARE

#define XCAM_3A_LIB_DESCRIPTION "xcam_3a_desciption"

typedef struct _XCam3AContext XCam3AContext;

/* C interface of 3A lib */
typedef struct _XCam3ADescription {
    uint32_t                               version;
    uint32_t                               size;
    XCamReturn (*create_context)           (XCam3AContext **context);
    XCamReturn (*destroy_context)          (XCam3AContext *context);
    XCamReturn (*configure_3a)             (XCam3AContext *context, uint32_t width, uint32_t height, double framerate);
    XCamReturn (*set_3a_stats)             (XCam3AContext *context, const struct atomisp_3a_statistics *stats);
    XCamReturn (*update_common_params)     (XCam3AContext *context, XCamCommonParam *params);
    XCamReturn (*analyze_awb)              (XCam3AContext *context, XCamAwbParam *params);
    XCamReturn (*analyze_ae)               (XCam3AContext *context, XCamAeParam *params);
    XCamReturn (*analyze_af)               (XCam3AContext *context, XCamAfParam *params);
    XCamReturn (*combine_analyze_results)  (XCam3AContext *context, XCam3aResultHead **results, uint32_t *res_count);
    void       (*free_results)             (XCam3aResultHead *results, uint32_t res_count);
} XCam3ADescription;

XCAM_END_DECLARE

#endif //C_XCAM_3A_DESCRIPTION_H