#ifndef _SCI_IO_H_
#define _SCI_IO_H_

//#############################################################################
//
//! \file   f2802x/common/include/sci_io.h
//!
//! \brief  Contains public interface to various functions related
//!         to the serial communications interface (SCI) object
//
//  Group:          C2000
//  Target Device:  TMS320F2802x
//
//#############################################################################
// $TI Release: F2802x Support Library v3.03.00.00 $
// $Release Date: Tue May 26 17:09:17 IST 2020 $
// $Copyright:
// Copyright (C) 2009-2020 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// $
//#############################################################################

//!
//! \defgroup SCI_IO

//!
//! \ingroup SCI_IO
//@{

#ifdef __cplusplus
extern "C" {
#endif
#include <sys/types.h>


//
// Function Prototypes
//
int SCI_open(const char * path, unsigned flags, int llv_fd);
int SCI_close(int dev_fd);
int SCI_read(int dev_fd, char * buf, unsigned count);
int SCI_write(int dev_fd, const char * buf, unsigned count);
off_t SCI_lseek(int dev_fd, off_t offset, int origin);
int SCI_unlink(const char * path);
int SCI_rename(const char * old_name, const char * new_name);

#ifdef __cplusplus
}
#endif // extern "C"

//@}  // ingroup

#endif // end of _SCI_H_ definition

//
// End of File
//

