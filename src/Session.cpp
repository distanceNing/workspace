//
// Created by yangning on 18-1-14.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//

#include "headers/Session.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/reader.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;

static const char* begin = "BEGIN";
static const char* end = "END";

/*
static char* sendbuffer[MAX_BUFFER_SIZE];
static char* recvbuffer[MAX_BUFFER_SIZE];
static char* filename[MAX_FILENAME_SIZE];
*/

void Session::handleRequest(net::TcpConnection& connection, net::SocketBuf* buf)
{
    if(!parse(buf))
		return;

    //至此协议解析成功
    //下面做业务逻辑的处理
    process();

    //回复客户端处理结果
    std::string reply(Protocol::jsonObjToString(replyJson_));
    connection.sendMessage(reply.c_str(),reply.length());

	switch (handleState_) {
		case :
		default:break;
	}
}

void Session::process() {
    Value::ConstMemberIterator itr = json->FindMember("cmd");
    if (itr == json->MemberEnd())
        return ;
    int cmd_type = atoi(itr->value.GetString());
    switch (cmd_type)
    {
	    case kCmdRegister:
		    handleState_ = Session::kCmdRegisterFuc();
		    break;
	    case kCmdLogin:
		    handleState_ = Session::kCmdLoginFunc();
		    break;
	    case kCmdAck:
		    handleState_ = Session::kCmdAckErrorFunc(cmd_type);
		    break;
	    case kCmdError:
		    handleState_ = Session::kCmdAckErrorFunc(cmd_type);
		    break;
	    case kCmdDownload:
		    break;
	    case kCmdUpload:
		    break;
	    case kCmdUpdatePath:
		    break;
	    case kCmdReTrans:
		    break;
	    case kCmdContinue:
		    break;
	    case kCmdStop:
		    break;
	    case kCmdLogout:
		    break;
	    case kCmdVip:
		    break;
        default:break;
    }
}

bool Session::parse(net::SocketBuf* buf)
{
    if(buf->readableBytes() <= 8)
    {
        //接收到的数据太少,返回等待下次数据到达
        return false;
    }
    const char* str= buf->readBegin();
    size_t len =buf->readableBytes();
    if(strncmp(str,begin,strlen(begin))!= 0 )
    {
        //数据块错误没有包含BEGIN
        return false;
    }

    const char* flag=std::search(str+strlen(begin),str+len,end,end+3);
    if(flag ==str+len)
    {
        //接收到的数据中没有END
        return false;
    }

    std::string json_str(str + strlen(begin),flag);

    json = Protocol::stringToJsonObj(json_str);

    return true;
}

int Session::kCmdAckErrorFunc (int cmd_type) {
	replyJson_.SetObject();
	Document::AllocatorType & allcotor = replyJson_.GetAllocator();

	const char* cmd = "cmd";
	if (cmd_type == 3) {
		const char* ack = "kCmdAck";
	} else if (cmd_type == 4) {
		const char* ack = "kCmdError";
	}
	replyJson_.AddMember(rapidjson::StringRef(cmd), rapidjson::StringRef(ack), allcotor);

	StringBuffer buffer;
	Writer<StringBuffer>writer(buffer);
	replyJson_.Accept(writer);
	const std::string message = replyJson_.GetString();

	if (message != NULL) {
		return 1;
	} else {
		return 2;
	}
}

int Session::kCmdRegisterFuc () {
	/*
	 * 查询数据库是否存在此人，不存在则返回确认，否则返回重名错误
	 *
	 * */
	int queryRes;
	replyJson_.Clear();
	int res = Session::kCmdAckErrorFunc(queryRes);
	if (res == 1) {
		return 1;
	} else {
		return 2;
	}
}

int Session::kCmdLoginFunc () {
	/*查询数据库，如果存在并密码正确则返回确认，否则返回登录失败（考虑密码错误）*/
	/*
	 * 代码
	 *
	 */
	int queryRes;
	replyJson_.Clear();
	int res = Session::kCmdAckErrorFunc(queryRes);
	if (res == 1) {
		return 1;
	} else {
		return 0;
	}
}

int Session::kCmdDownloadFunc () {

	/*
	 * 读取接收到的路径和文件名,查找文件进行传输
	 * 调用下载模块
	 *
	 * */

	int queryRes;
	replyJson_.Clear();
	int res = Session::kCmdAckErrorFunc(queryRes);
	if (res == 1) {
		return 1;
	} else {
		return 0;
	}
}

int Session::kCmdUploadFunc () {
	/*
	 *
	 * 根据接收的md5,判断文件是否存在(秒传)，若存在直接返回，否则进行分块接收。
	 * 调用服务器上传模块
	 *
	 * */

	int queryRes;
	replyJson_.Clear();
	int res = Session::kCmdAckErrorFunc(queryRes);
	if (res == 1) {
		return 1;
	} else {
		return 0;
	}
}

int Session::kCmdReTransFunc () {
	/*
	 * 调用重传模块
	 *
	 * */

	int queryRes;
	replyJson_.Clear();
	int res = Session::kCmdAckErrorFunc(queryRes);
	if (res == 1) {
		return 1;
	} else {
		return 0;
	}
}

int Session::kCmdContinueFunc () {
	/*
	 * 调用继续上传模块
	 *
	 *
	 * */

	int queryRes;
	replyJson_.Clear();
	int res = Session::kCmdAckErrorFunc(queryRes);
	if (res == 1) {
		return 1;
	} else {
		return 0;
	}
}

int Session::kCmdStopFunc () {
	/*
	 * 调用暂停模块
	 *
	 *
	 * */

	int queryRes;
	replyJson_.Clear();
	int res = Session::kCmdAckErrorFunc(queryRes);
	if (res == 1) {
		return 1;
	} else {
		return 0;
	}
}

int Session::kCmdLogoutFunc () {
	/*
	 * 调用退出模块
	 *
	 *
	 * */

	int queryRes;
	replyJson_.Clear();
	int res = Session::kCmdAckErrorFunc(queryRes);
	if (res == 1) {
		return 1;
	} else {
		return 0;
	}
}

int Session::kCmdVipFunc () {
	/*
	 * 调用VIP模块
	 *
	 *
	 * */

	int queryRes;
	replyJson_.Clear();
	int res = Session::kCmdAckErrorFunc(queryRes);
	if (res == 1) {
		return 1;
	} else {
		return 0;
	}
}





