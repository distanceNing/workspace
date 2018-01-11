//
// Created by yangning on 18-1-11.
//
// Descriprion :
//
// Copyright (c) yangning All rights reserved.
//


TcpSocket() sendMsg()

User
{
    void userRegister(user_info&)
    {
        cmd_reg

    }
    void userLogin(login_info&)
    {}

    void downLoad(filename)
    {}

    void upload(filename)
    {
        if ( is dir )
        {
            dirToJsonType
        }
        sendFileInfo();

    }


}




server:

MYSQL connect
      query

Session{

    request
    process()
    {
        switch
            cmd_reg
            cmd_upload
            handleUpload()
            cmd_download

        return response
    }

void handleUpload(filemd5)
{
    if(findExisted()) {
        showMsg(true);
    }
    else {
        showMsg();

        prepareRecv();


    }
}

void    handleDownload(filename,filemd5)
{
        call download
}
    bool findExisted()
    {

    }


modle download
        {
                sendFileInfo()

                if(is dir)
                    zip

                splitFile()

                sendFileBlock()

        };


    TcpConn



}



