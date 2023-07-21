/************************************************************************
 *File name:
 *Description:
 *
 *Current Version:
 *Author: modify by sunjiawei
 *Date: 2022.06
************************************************************************/


#ifndef _ESL_THREADMUTEX_H
#define _ESL_THREADMUTEX_H

#include "esl.h"

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */

typedef struct esl_mutex esl_mutex_t;
typedef struct esl_thread esl_thread_t;
typedef void *(*esl_thread_function_t) (esl_thread_t *, void *);

ESL_DECLARE(esl_status_t) esl_thread_create_detached(esl_thread_function_t func, void *data);
esl_status_t esl_thread_create_detached_ex(esl_thread_function_t func, void *data, size_t stack_size);
void esl_thread_override_default_stacksize(size_t size);
ESL_DECLARE(esl_status_t) esl_mutex_create(esl_mutex_t **mutex);
ESL_DECLARE(esl_status_t) esl_mutex_destroy(esl_mutex_t **mutex);
ESL_DECLARE(esl_status_t) esl_mutex_lock(esl_mutex_t *mutex);
ESL_DECLARE(esl_status_t) esl_mutex_trylock(esl_mutex_t *mutex);
ESL_DECLARE(esl_status_t) esl_mutex_unlock(esl_mutex_t *mutex);

#ifdef __cplusplus
}
#endif /* defined(__cplusplus) */

#endif /* defined(_ESL_THREADMUTEX_H) */

/* For Emacs:
 * Local Variables:
 * mode:c
 * indent-tabs-mode:t
 * tab-width:4
 * c-basic-offset:4
 * End:
 * For VIM:
 * vim:set softtabstop=4 shiftwidth=4 tabstop=4 noet:
 */
