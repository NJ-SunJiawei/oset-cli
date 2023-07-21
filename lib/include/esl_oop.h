/************************************************************************
 *File name:
 *Description:
 *
 *Current Version:
 *Author: modify by sunjiawei
 *Date: 2022.06
************************************************************************/

#ifndef _ESL_OOP_H_
#define _ESL_OOP_H_
#include <esl.h>
#ifdef __cplusplus
extern "C" { 
#endif

//#define this_check(x) do { if (!this) { esl_log(ESL_LOG_ERROR, "object is not initalized\n"); return x;}} while(0)
#define this_check(x) do { if (0) { esl_log(ESL_LOG_ERROR, "object is not initalized\n"); return x;}} while(0)

#define this_check_void() do { if (!this) { esl_log(ESL_LOG_ERROR, "object is not initalized\n"); return;}} while(0)


class ESLevent {
 private:
	esl_event_header_t *hp;
 public:
	esl_event_t *event;
	char *serialized_string;
	int mine;

	ESLevent(const char *type, const char *subclass_name = NULL);
	ESLevent(esl_event_t *wrap_me, int free_me = 0);
	ESLevent(ESLevent *me);
	virtual ~ESLevent();
	const char *serialize(const char *format = NULL);
	bool setPriority(esl_priority_t priority = ESL_PRIORITY_NORMAL);
	const char *getHeader(const char *header_name, int idx = -1);
	char *getBody(void);
	const char *getType(void);
	bool addBody(const char *value);
	bool addHeader(const char *header_name, const char *value);
	bool pushHeader(const char *header_name, const char *value);
	bool unshiftHeader(const char *header_name, const char *value);
	bool delHeader(const char *header_name);
	const char *firstHeader(void);
	const char *nextHeader(void);
};



class ESLconnection {
 private:
	esl_handle_t handle;
 public:
	ESLconnection(const char *host, const int port, const char *user, const char *password);
	ESLconnection(const char *host, const int port, const char *password);
	ESLconnection(const char *host, const char *port, const char *user, const char *password);
	ESLconnection(const char *host, const char *port, const char *password);
	ESLconnection(int socket);
	virtual ~ESLconnection();
	int socketDescriptor();
	int connected();
	ESLevent *getInfo();
	int send(const char *cmd);
	ESLevent *sendRecv(const char *cmd);
	ESLevent *api(const char *cmd, const char *arg = NULL);
	ESLevent *bgapi(const char *cmd, const char *arg = NULL, const char *job_uuid = NULL);
	ESLevent *sendEvent(ESLevent *send_me);
	int sendMSG(ESLevent *send_me, const char *uuid = NULL);
	ESLevent *recvEvent();
	ESLevent *recvEventTimed(int ms);
	ESLevent *filter(const char *header, const char *value);
	int events(const char *etype, const char *value);
	ESLevent *execute(const char *app, const char *arg = NULL, const char *uuid = NULL);
	ESLevent *executeAsync(const char *app, const char *arg = NULL, const char *uuid = NULL);
	int setAsyncExecute(const char *val);
	int setEventLock(const char *val);
	int disconnect(void);
};

void eslSetLogLevel(int level);



#ifdef __cplusplus
}
#endif

#endif

/* For Emacs:
 * Local Variables:
 * mode:c++
 * indent-tabs-mode:t
 * tab-width:4
 * c-basic-offset:4
 * End:
 * For VIM:
 * vim:set softtabstop=4 shiftwidth=4 tabstop=4 noet:
 */
