--创建序列
create sequence  seq_demo ;   

/*==============================================================*/
/* DBMS name:      ORACLE Version 10gR2                         */
/* Created on:     2015/5/25 14:55:58                           */
/*==============================================================*/


alter table goods2
   drop constraint FK_GOODS2_REFERENCE_GOODSTYP;

alter table orderDetail
   drop constraint FK_ORDERDET_REFERENCE_ORDERS;

alter table orderDetail
   drop constraint FK_ORDERDET_REFERENCE_GOODS2;

alter table orders
   drop constraint FK_ORDERS_REFERENCE_USERS;

drop table goods2 cascade constraints;

drop table goodstypes cascade constraints;

drop table manager cascade constraints;

drop table orderDetail cascade constraints;

drop table orders cascade constraints;

drop table users cascade constraints;


/*==============================================================*/
/* Table: goodstypes                                            */
/*==============================================================*/
create table goodstypes  (
   typeid               NUMBER(10,0)                    not null,
   typename             VARCHAR2(20)                    not null,
   constraint PK_GOODSTYPES primary key (typeid)
);

comment on table goodstypes is
'商品类别表，用户存储。。。。。。。。';

comment on column goodstypes.typename is
'类别名称尽量定义在10个字符以内';

/*==============================================================*/
/* Table: manager                                               */
/*==============================================================*/
create table manager  (
   mid                  number(12)                      not null,
   loginName            varchar2(20)                    not null,
   loginPwd             varchar2(32)                    not null,
   managerName          varchar2(32),
   phone                varchar2(12),
   constraint PK_MANAGER primary key (mid),
   constraint AK_KEY_2_MANAGER unique (loginName)
);

comment on column manager.loginName is
'帐号不允许重复';

/*==============================================================*/
/* Table: orderDetail                                           */
/*==============================================================*/
create table orderDetail  (
   did                  number(12)                      not null,
   oid                  number(10),
   gid                  NUMBER(10,0),
   numb                 NUMBER(10),
   private              NUMBER(10,0),
   total                NUMBER(10),
   constraint PK_ORDERDETAIL primary key (did)
);

/*==============================================================*/
/* Table: orders                                                */
/*==============================================================*/
create table orders  (
   oid                  number(10)                      not null,
   "uid"                number(12),
   oDate                date                            not null,
   reciveAddr           varchar2(50)                    not null,
   recive               varchar2(50)                    not null,
   recivePhone          varchar2(50)                    not null,
   reciveType           varchar2(50)                    not null,
   reciveDate           varchar2(50)                    not null,
   totalPrice           varchar2(50)                    not null,
   stsuts               number(1)                       not null,
   constraint PK_ORDERS primary key (oid)
);

/*==============================================================*/
/* Table: users                                                 */
/*==============================================================*/
create table users  (
   userid               number(12)                      not null,
   loginName            varchar2(20)                    not null,
   pwd                  varchar2(32)                    not null,
   userName             varchar2(32),
   phone                varchar2(32),
   address              varchar2(32),
   constraint PK_USERS primary key (userid)
);

alter table goods2
   add constraint FK_GOODS2_REFERENCE_GOODSTYP foreign key (typeid)
      references goodstypes (typeid);

alter table orderDetail
   add constraint FK_ORDERDET_REFERENCE_ORDERS foreign key (oid)
      references orders (oid);

alter table orderDetail
   add constraint FK_ORDERDET_REFERENCE_GOODS2 foreign key (gid)
      references goods2 (gid);

alter table orders
   add constraint FK_ORDERS_REFERENCE_USERS foreign key ("uid")
      references users (userid);

drop table goods2
create table goods2 (
   gid                  NUMBER(10,0)                    not null,
   typeid               NUMBER(10,0),
   gname                VARCHAR2(20)                    not null,
   price                NUMBER(8,2),
   salPrice             NUMBER(8,2)                     not null,
   image                VARCHAR2(100),
   numb                 number(8),
   constraint PK_GOODS2 primary key (gid)
);
create table goods3 (
   gid                  NUMBER(10,0)                    not null,
   typeid               NUMBER(10,0),
   gname                VARCHAR2(20)                    not null,
   price                NUMBER(8,2),
   salPrice             NUMBER(8,2)                     not null,
   image                VARCHAR2(100),
   numb                 number(8),
   constraint PK_GOODS3 primary key (gid)
);

--初始化脚本,往表中插入一些初始化数据，方便操作。
--用户表
insert into users (userid ,loginname,pwd) values(1,'admin','123456');

--商品类别表
insert into goodstypes values(1,'手机数码');

--商品表
insert into goods2 values(1,1,'iPhone5s',4288,3000,'/images/iphone5s.png',0);
insert into goods2 values(2,1,'酷派大神',1288,288,'/images/coolpad.png',0);

--管理员
insert into manager values(1,'manager','123456','管理员','7788520');
commit;
select * from users;
select * from goods2;
select * from goods3;
update goods2 set salprice=salprice+100 where gid=2;
insert into goods3 select * from goods2 where gid=2
delete goods3 where gid=2