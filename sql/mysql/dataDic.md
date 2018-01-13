user
(
	user_id 		--主键。用户的唯一标识
	user_passwd 	--用户的密码
	user_name 		--用户的名称（可以重复）
	login_time 		--用户登陆时间
	login_ip 		--用户登陆ip
	login_status 	--用户登录状态（1：表示登陆  0：表示未登录）
	user_vip 		--用户的权限状态（1：表示会员  0：表示普通）
)

user_info
(
	user_info_id 	--主键。
	user_email 		--用户的邮箱
	user_birthday 	--用户的生日
	user_phone 		--用户的电话
	sign_time 		--用户注册的时间
	sign_ip 		--用户注册的ip
	sign_status 	--用户注册的状态（0：表示未验证  1：表示已验证）
	user_id 		--外键。用户的唯一标识
)

file
(
	file_md5 		--主键。文件的md5，唯一标识
	file_name 		--文件名
	file_size 		--文件的大小
	file_type 		--文件的类型
	file_count 		--文件在服务器上的引用次数（有多少人上传过此文件）
	file_path 		--文件在服务器上的路径
	file_remark 	--预留字段
)

user_file
(
	user_file_id 	--主键。
	user_file_name 	--文件名
	user_file_time 	--用户文件的上传时间
	user_file_ip 	--用户文件上传ip
	user_file_status --用户文件状态（是否被使用，防止误操作）
	user_file_hide 	--用户文件是否被隐藏
	user_file_permission --用户对文件的权限
	user_file_path 	--用户文件在用户目录树的存放路径
	file_md5 		--外键。文件的md5
	user_id 		--外键。用户的唯一标识
	user_file_remark--预留字段 
)

directory
(
	dir_id 			--联合主键。文件夹的唯一标识（外键）
	user_id 		--联合主键。用户的唯一标识（外键）
	dir_parent 		--文件夹的父目录，用来返回上一级
	dir_time 		--文件夹的上传或者修改时间
	dir_status 		--文件夹的状态，防止误操作
	dir_name 		--文件夹的名称
)

file_dir
(
	file_dir_id 	--主键。
	dir_id 			--外键。文件夹的唯一标识
	file_md5 		--外键。文件的md5
)

