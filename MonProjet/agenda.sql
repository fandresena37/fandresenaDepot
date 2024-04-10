create user 'fandresena'@'localhost' identified with mysql_native_password by 'Azerty123!';
grant all privileges on *.* to 'fandresena'@'localhost';
flush privileges;
create database agenda;
use agenda;
create table login(user text not null,password text not null); 
