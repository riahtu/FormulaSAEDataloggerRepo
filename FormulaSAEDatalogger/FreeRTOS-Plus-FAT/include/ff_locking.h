/*
 * FreeRTOS+FAT Labs Build 160919a (C) 2016 Real Time Engineers ltd.
 * Authors include James Walmsley, Hein Tibosch and Richard Barry
 *
 *******************************************************************************
 ***** NOTE ******* NOTE ******* NOTE ******* NOTE ******* NOTE ******* NOTE ***
 ***                                                                         ***
 ***                                                                         ***
 ***   FREERTOS+FAT IS STILL IN THE LAB:                                     ***
 ***                                                                         ***
 ***   Be aware we are still refining the FreeRTOS+FAT design,               ***
 ***   the source code does not yet fully conform to the strict quality and  ***
 ***   style standards mandated by Real Time Engineers ltd., and the         ***
 ***   documentation and testing is not necessarily complete.                ***
 ***                                                                         ***
 ***   PLEASE REPORT EXPERIENCES USING THE SUPPORT RESOURCES FOUND ON THE    ***
 ***   URL: http://www.FreeRTOS.org/contact  Active early adopters may, at   ***
 ***   the sole discretion of Real Time Engineers Ltd., be offered versions  ***
 ***   under a license other than that described below.                      ***
 ***                                                                         ***
 ***                                                                         ***
 ***** NOTE ******* NOTE ******* NOTE ******* NOTE ******* NOTE ******* NOTE ***
 *******************************************************************************
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * 1 tab == 4 spaces!
 *
 * http://www.FreeRTOS.org
 * http://www.FreeRTOS.org/plus
 * http://www.FreeRTOS.org/labs
 *
 */

/**
 *	@file		ff_locking.h
 *	@ingroup	LOCKING
 **/

#ifndef _FF_LOCKING_H_
#define	_FF_LOCKING_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

/*---------- PROTOTYPES (in order of appearance). */

/* PUBLIC: */


/* PRIVATE: */
void		FF_PendSemaphore		( void *pSemaphore );
BaseType_t	FF_TrySemaphore			( void *pSemaphore, uint32_t TimeMs );
void		FF_ReleaseSemaphore		( void *pSemaphore );
void		FF_Sleep				( uint32_t TimeMs );

/* Create an event group and bind it to an I/O manager. */
BaseType_t	FF_CreateEvents( FF_IOManager_t *pxIOManager );

/* Delete an event group. */
void FF_DeleteEvents( FF_IOManager_t *pxIOManager );

/* Get a lock on all DIR operations for a given I/O manager. */
void FF_LockDirectory( FF_IOManager_t *pxIOManager );

/* Release the lock on all DIR operations. */
void FF_UnlockDirectory( FF_IOManager_t *pxIOManager );

/* Get a lock on all FAT operations for a given I/O manager. */
void FF_LockFAT( FF_IOManager_t *pxIOManager );

/* Release the lock on all FAT operations. */
void FF_UnlockFAT( FF_IOManager_t *pxIOManager );

/* Called from FF_GetBuffer() as long as no buffer is available. */
BaseType_t FF_BufferWait( FF_IOManager_t *pxIOManager, uint32_t xWaitMS );

/* Called from FF_ReleaseBuffer(). */
void FF_BufferProceed( FF_IOManager_t *pxIOManager );

/* Check if the current task already has locked the FAT. */
int FF_Has_Lock( FF_IOManager_t *pxIOManager, uint32_t aBits );

/*
 * Throw a configASSERT() in case the FAT has not been locked
 * by this task.
 */
/* _HT_ This function is only necessary while testing. */
void FF_Assert_Lock( FF_IOManager_t *pxIOManager, uint32_t aBits );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif	/* _FF_LOCKING_H_ */

