/************************************************************************
 *File name:
 *Description:
 *
 *Current Version:
 *Author: modify by sunjiawei
 *Date: 2022.06
************************************************************************/
#include "esl.h"
#ifndef ESL_JSON__h
#define ESL_JSON__h

#ifdef ESL_EXPORTS
#ifndef CJSON_EXPORT_SYMBOLS
#define CJSON_EXPORT_SYMBOLS 1
#endif
#endif

#ifdef SWITCH_API_VISIBILITY
#ifndef CJSON_API_VISIBILITY
#define CJSON_API_VISIBILITY 1
#endif
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include "esl_cJSON.h"
#include "esl_cJSON_Utils.h"
	
ESL_DECLARE(const char *)cJSON_GetObjectCstr(const cJSON *object, const char *string);

static inline cJSON *esl_json_add_child_obj(cJSON *json, const char *name, cJSON *obj)
{
	cJSON *new_json = NULL;

	esl_assert(json);

	if (obj) {
		new_json = obj;
	} else {
		new_json = cJSON_CreateObject();
	}

	esl_assert(new_json);

	cJSON_AddItemToObject(json, name, new_json);

	return new_json;
}

static inline cJSON *esl_json_add_child_array(cJSON *json, const char *name)
{
	cJSON *new_json = NULL;

	esl_assert(json);

	new_json = cJSON_CreateArray();
	esl_assert(new_json);

	cJSON_AddItemToObject(json, name, new_json);

	return new_json;
}

static inline cJSON *esl_json_add_child_string(cJSON *json, const char *name, const char *val)
{
	cJSON *new_json = NULL;

	esl_assert(json);

	new_json = cJSON_CreateString(val);
	esl_assert(new_json);

	cJSON_AddItemToObject(json, name, new_json);

	return new_json;
}

#ifdef __cplusplus
}
#endif

#endif
