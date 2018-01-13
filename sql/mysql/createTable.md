create table directory
(
	dir_id varchar(128) default '/' not null,
	user_id varchar(16) not null,
	dir_parent int not null,
	dir_time datetime not null,
	dir_status tinyint(1) not null,
	dir_name varchar(64) not null,
	primary key (dir_id, user_id)
)
engine=InnoDB
;

create index FK_user_dir
	on directory (user_id)
;

create table file
(
	file_md5 varchar(32) not null
		primary key,
	file_name varchar(128) not null,
	file_size mediumtext not null,
	file_type varchar(32) null,
	file_count int not null,
	file_path varchar(128) not null,
	file_remark varchar(32) null
)
engine=InnoDB
;

create table file_dir
(
	file_dir_id int auto_increment
		primary key,
	dir_id varchar(128) default '/' not null,
	file_md5 varchar(32) null,
	constraint FK_dir_file_dir
		foreign key (dir_id) references directory (dir_id),
	constraint FK_file_file_dir
		foreign key (file_md5) references file (file_md5)
)
engine=InnoDB
;

create index FK_dir_file_dir
	on file_dir (dir_id)
;

create index FK_file_file_dir
	on file_dir (file_md5)
;

create table user
(
	user_id varchar(16) not null
		primary key,
	user_passwd varchar(32) not null,
	user_name varchar(32) not null,
	login_time datetime null,
	login_ip varchar(32) null,
	login_status int not null,
	user_vip int not null
)
engine=InnoDB
;

alter table directory
	add constraint FK_user_dir
		foreign key (user_id) references user (user_id)
;

create table user_file
(
	user_file_id bigint auto_increment
		primary key,
	user_file_name varchar(128) not null,
	user_file_time datetime not null,
	user_file_ip varchar(32) not null,
	user_file_status tinyint(1) not null,
	user_file_hide tinyint(1) not null,
	user_file_permission int not null,
	user_file_path varchar(128) not null,
	file_md5 varchar(32) not null,
	user_id varchar(16) not null,
	user_file_remark varchar(32) null,
	constraint FK_file_user_file
		foreign key (file_md5) references file (file_md5),
	constraint FK_user_user_file
		foreign key (user_id) references user (user_id)
)
engine=InnoDB
;

create index FK_file_user_file
	on user_file (file_md5)
;

create index FK_user_user_file
	on user_file (user_id)
;

create table user_info
(
	user_info_id int auto_increment
		primary key,
	user_email varchar(32) null,
	user_birthday date null,
	user_phone smallint(6) null,
	sign_time datetime not null,
	sign_ip varchar(32) not null,
	sign_status int not null,
	user_id varchar(16) not null,
	constraint FK_user_user_info
		foreign key (user_id) references user (user_id)
)
engine=InnoDB
;

create index FK_user_user_info
	on user_info (user_id)
;

