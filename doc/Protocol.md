### Protocol

```
 cmd
 {
     kCmdLogin,
     kCmdRegister,
     kCmdAck,
     kCmdUpload,
     kCmdDownload,
     kCmdReTrans,
     kCmdLogout,
     kCmdUpdatePath,
     kCmdContinue

 }

```


```
module:

Register{
    kCmdRegister,
    user_id,
    user_name,
    user_passwd,
    user_email,
}

Login{
        kcmdLogin,
        user_id,
        user_passwd,
     }

Upload{
    kCmdUpload,
    filesize,
    filetype,
    filemd5,
    filepath,
}

Download{
    kCmdDownload,
    filename,
    filepath,
}


ContinueSend{
    kCmdContinue,
    block_num,
    block_md5,
}


FileBlock{
    block_num,
    block_md5,
    file_md5,
}

```
