create user 'fandresena'@'localhost' identified by 'Azerty123!';
grant all privileges on *.* to 'fandresena'@'localhost';
flush privileges;
create database agenda;
create table login(user text not null,password text not null); 
