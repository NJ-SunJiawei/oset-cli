/************************************************************************
 *File name:
 *Description:
 *
 *Current Version:
 *Author: modify by sunjiawei
 *Date: 2022.06
************************************************************************/

#include "esl.h"

ESL_DECLARE(const char *)cJSON_GetObjectCstr(const cJSON *object, const char *string)
{
       cJSON *cj = cJSON_GetObjectItem(object, string);

	   if (!cj || cj->type != cJSON_String || !cj->valuestring) return NULL;

	   return cj->valuestring;
}

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
