### 数据库执行的功能：
## 注册

```
以下插入操作为注册操作，要插入的字段均需要填入，user_vip默认0为非vip,user_vip为1则后续升级为vip用户,随着用户注册信息的同时，user_info表也要更新。
INSERT INTO user(user_id, user_passwd, user_name, login_status, user_vip) VALUES ("", "", "", 0, 0);

INSERT user_info(user_email, sign_time, sign_ip, user_id) VALUES("", "", "", );


帮助文档的信息录入(user_file表)
INSERT INTO user_file(user_id, file_md5, user_file_name, user_file_time, user_file_ip) VALUES("", "", "帮助文档.txt", "1970-01-01", ""); 
INSERT INTO file(file_md5, file_name, file_size, file_type, file_count, file_path) VALUES("", "帮助文档.txt", , "txt", 1, "/");

文件夹表也随着用户的注册填入
INSERT INTO directory(dir_id, user_id, dir_time, dir_name) VALUES("/", "", "", "帮助文档.txt");

file_dir也跟着用户注册填入信息
INSERT INTO file_dir(dir_id, file_md5) VALUES("", "");
```

## 登录
```
判断登录帐号是否存在
SELECT userid, userpasswd FROM user WHERE *userid='userid'; 
```

## 文件(夹)上传
```
上传文件所需要执行的语句：
写入文件信息:
file_type可以不插入(表中可为null)
    INSERT INTO file(file_md5, file_name, file_size, file_type, file_count, file_path) VALUES("", "", "", "", "");

写入文件的同时插入用户文件信息：
    INSERT INTO user_file(user_file_name, user_file_time, user_file_permission, user_file_status, user_file_hide, user_file_ip, user_file_path, file_md5, user_id) VALUES();
	
写入文件的同时插入directory表 #dir_parent可以为空
    INSERT INTO directory(dir_id, user_id, dir_parent, dir_time, dir_status, dir_name) VALUES("", "", "", "", , "");

随后更新file_dir
    INSERT INTO file_dir(dir_id, file_md5) VALUES("", "");
```

```
写入文件夹信息：
INSERT INTO directory(dir_id, user_id, dir_parent, dir_parent, dir_time, dir_status, dir_name) VALUES();
INSERT INTO file_dir(dir_id) VALUES("");
```

## 非活跃文件删除
DELETE FROM file WHERE file_count<1;




