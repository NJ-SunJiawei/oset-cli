/************************************************************************
 *File name:
 *Description:
 *
 *Current Version:
 *Author: modify by sunjiawei
 *Date: 2022.06
************************************************************************/

#include "esl.h"
#ifndef ESL_BUFFER_H
#define ESL_BUFFER_H
/**
 * @defgroup esl_buffer Buffer Routines
 * @ingroup buffer
 * The purpose of this module is to make a plain buffering interface that can be used for read/write buffers
 * throughout the application.
 * @{
 */
struct esl_buffer;
typedef struct esl_buffer esl_buffer_t;

/*! \brief Allocate a new dynamic esl_buffer 
 * \param buffer returned pointer to the new buffer
 * \param blocksize length to realloc by as data is added
 * \param start_len ammount of memory to reserve initially
 * \param max_len length the buffer is allowed to grow to
 * \return status
 */
ESL_DECLARE(esl_status_t) esl_buffer_create(esl_buffer_t **buffer, esl_size_t blocksize, esl_size_t start_len, esl_size_t max_len);

/*! \brief Get the length of a esl_buffer_t 
 * \param buffer any buffer of type esl_buffer_t
 * \return int size of the buffer.
 */
ESL_DECLARE(esl_size_t) esl_buffer_len(esl_buffer_t *buffer);

/*! \brief Get the freespace of a esl_buffer_t 
 * \param buffer any buffer of type esl_buffer_t
 * \return int freespace in the buffer.
 */
ESL_DECLARE(esl_size_t) esl_buffer_freespace(esl_buffer_t *buffer);

/*! \brief Get the in use amount of a esl_buffer_t 
 * \param buffer any buffer of type esl_buffer_t
 * \return int ammount of buffer curently in use
 */
ESL_DECLARE(esl_size_t) esl_buffer_inuse(esl_buffer_t *buffer);

/*! \brief Read data from a esl_buffer_t up to the ammount of datalen if it is available.  Remove read data from buffer. 
 * \param buffer any buffer of type esl_buffer_t
 * \param data pointer to the read data to be returned
 * \param datalen amount of data to be returned
 * \return int ammount of data actually read
 */
ESL_DECLARE(esl_size_t) esl_buffer_read(esl_buffer_t *buffer, void *data, esl_size_t datalen);

ESL_DECLARE(esl_size_t) esl_buffer_read_packet(esl_buffer_t *buffer, void *data, esl_size_t maxlen);
ESL_DECLARE(esl_size_t) esl_buffer_packet_count(esl_buffer_t *buffer);

/*! \brief Read data endlessly from a esl_buffer_t 
 * \param buffer any buffer of type esl_buffer_t
 * \param data pointer to the read data to be returned
 * \param datalen amount of data to be returned
 * \return int ammount of data actually read
 * \note Once you have read all the data from the buffer it will loop around.
 */
ESL_DECLARE(esl_size_t) esl_buffer_read_loop(esl_buffer_t *buffer, void *data, esl_size_t datalen);

/*! \brief Assign a number of loops to read
 * \param buffer any buffer of type esl_buffer_t
 * \param loops the number of loops (-1 for infinite)
 */
ESL_DECLARE(void) esl_buffer_set_loops(esl_buffer_t *buffer, int32_t loops);

/*! \brief Write data into a esl_buffer_t up to the length of datalen
 * \param buffer any buffer of type esl_buffer_t
 * \param data pointer to the data to be written
 * \param datalen amount of data to be written
 * \return int amount of buffer used after the write, or 0 if no space available
 */
ESL_DECLARE(esl_size_t) esl_buffer_write(esl_buffer_t *buffer, const void *data, esl_size_t datalen);

/*! \brief Remove data from the buffer
 * \param buffer any buffer of type esl_buffer_t
 * \param datalen amount of data to be removed
 * \return int size of buffer, or 0 if unable to toss that much data
 */
ESL_DECLARE(esl_size_t) esl_buffer_toss(esl_buffer_t *buffer, esl_size_t datalen);

/*! \brief Remove all data from the buffer
 * \param buffer any buffer of type esl_buffer_t
 */
ESL_DECLARE(void) esl_buffer_zero(esl_buffer_t *buffer);

/*! \brief Destroy the buffer
 * \param buffer buffer to destroy
 * \note only neccessary on dynamic buffers (noop on pooled ones)
 */
ESL_DECLARE(void) esl_buffer_destroy(esl_buffer_t **buffer);

/*! \brief Seek to offset from the beginning of the buffer
 * \param buffer buffer to seek
 * \param datalen offset in bytes
 * \return new position
 */
ESL_DECLARE(esl_size_t) esl_buffer_seek(esl_buffer_t *buffer, esl_size_t datalen);

/** @} */

ESL_DECLARE(esl_size_t) esl_buffer_zwrite(esl_buffer_t *buffer, const void *data, esl_size_t datalen);

#endif
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
