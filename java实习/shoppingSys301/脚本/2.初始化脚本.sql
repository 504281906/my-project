--初始化脚本,往表中插入一些初始化数据，方便操作。
--用户表
insert into users (userid ,loginname,pwd) values(1,'admin','123456');

--商品类别表
insert into goodstypes values(1,'手机数码');

--商品表
insert into goods2 values(1,1,'iPhone5s',4288,3000,'/images/iphone5s.png');
insert into goods2 values(2,1,'酷派大神',1288,288,'/images/coolpad.png');

--管理员
insert into manager values(1,'manager','123456','管理员','7788520');
commit;