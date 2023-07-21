/************************************************************************
 *File name:
 *Description:
 *
 *Current Version:
 *Author: modify by sunjiawei
 *Date: 2022.06
************************************************************************/

/**
 * @defgroup config Config File Parser
 * @ingroup config
 * This module implements a basic interface and file format parser
 * 
 * <pre>
 *
 * EXAMPLE 
 * 
 * [category1]
 * var1 => val1
 * var2 => val2
 * \# lines that begin with \# are comments
 * \#var3 => val3
 * </pre>
 * @{
 */

#ifndef ESL_CONFIG_H
#define ESL_CONFIG_H

#include "esl.h"

#ifdef __cplusplus
extern "C" {
#endif /* defined(__cplusplus) */


#define ESL_URL_SEPARATOR "://"


#ifdef WIN32
#define ESL_PATH_SEPARATOR "\\"
#ifndef ESL_CONFIG_DIR
#define ESL_CONFIG_DIR "c:\\openesl"
#endif
#define esl_is_file_path(file) (*(file +1) == ':' || *file == '/' || strstr(file, SWITCH_URL_SEPARATOR))
#else
#define ESL_PATH_SEPARATOR "/"
#ifndef ESL_CONFIG_DIR
#define ESL_CONFIG_DIR "/etc/openesl"
#endif
#define esl_is_file_path(file) ((*file == '/') || strstr(file, SWITCH_URL_SEPARATOR))
#endif

/*!
  \brief Evaluate the truthfullness of a string expression
  \param expr a string expression
  \return true or false 
*/
static __inline__ int esl_true(const char *expr) {
	return (expr && (!strcasecmp(expr, "yes")
					 || !strcasecmp(expr, "on")
					 || !strcasecmp(expr, "true")
					 || !strcasecmp(expr, "enabled")
					 || !strcasecmp(expr, "active")
					 || !strcasecmp(expr, "allow")
					 || atoi(expr)));
}

/*!
  \brief Evaluate the falsefullness of a string expression
  \param expr a string expression
  \return true or false 
*/
static __inline__ int esl_false(const char *expr) {
	return (expr && (!strcasecmp(expr, "no")
					 || !strcasecmp(expr, "off")
					 || !strcasecmp(expr, "false")
					 || !strcasecmp(expr, "disabled")
					 || !strcasecmp(expr, "inactive")
					 || !strcasecmp(expr, "disallow")
					 || !atoi(expr)));
}

typedef struct esl_config esl_config_t;

/*! \brief A simple file handle representing an open configuration file **/
struct esl_config {
	/*! FILE stream buffer to the opened file */
	FILE *file;
	/*! path to the file */
	char path[1024];
	/*! current category */
	char category[256];
	/*! current section */
	char section[256];
	/*! buffer of current line being read */
	char buf[1024];
	/*! current line number in file */
	int lineno;
	/*! current category number in file */
	int catno;
	/*! current section number in file */
	int sectno;

	int lockto;
};

/*!
  \brief Open a configuration file
  \param cfg (esl_config_t *) config handle to use
  \param file_path path to the file
  \return 1 (true) on success 0 (false) on failure
*/
ESL_DECLARE(int) esl_config_open_file(esl_config_t * cfg, const char *file_path);

/*!
  \brief Close a previously opened configuration file
  \param cfg (esl_config_t *) config handle to use
*/
ESL_DECLARE(void) esl_config_close_file(esl_config_t * cfg);

/*!
  \brief Retrieve next name/value pair from configuration file
  \param cfg (esl_config_t *) config handle to use
  \param var pointer to aim at the new variable name
  \param val pointer to aim at the new value
*/
ESL_DECLARE(int) esl_config_next_pair(esl_config_t * cfg, char **var, char **val);

/*!
  \brief Retrieve the CAS bits from a configuration string value
  \param strvalue pointer to the configuration string value (expected to be in format whatever:xxxx)
  \param outbits pointer to aim at the CAS bits
*/
ESL_DECLARE(int) esl_config_get_cas_bits(char *strvalue, unsigned char *outbits);


/** @} */

#ifdef __cplusplus
}
#endif /* defined(__cplusplus) */

#endif /* defined(ESL_CONFIG_H) */

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
