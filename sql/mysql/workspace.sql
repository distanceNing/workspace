-- MySQL dump 10.13  Distrib 5.7.20, for Linux (x86_64)
--
-- Host: localhost    Database: workspace
-- ------------------------------------------------------
-- Server version	5.7.20-0ubuntu0.16.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `directory`
--

DROP TABLE IF EXISTS `directory`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `directory` (
  `dir_id` int(11) NOT NULL AUTO_INCREMENT,
  `dir_name` varchar(128) NOT NULL,
  `dir_parent` int(11) NOT NULL,
  `dir_time` datetime NOT NULL,
  `dir_status` tinyint(1) NOT NULL,
  `user_id` varchar(16) NOT NULL,
  PRIMARY KEY (`dir_id`),
  KEY `FK_user_directory` (`user_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `directory`
--

LOCK TABLES `directory` WRITE;
/*!40000 ALTER TABLE `directory` DISABLE KEYS */;
/*!40000 ALTER TABLE `directory` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `file`
--

DROP TABLE IF EXISTS `file`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `file` (
  `file_md5` varchar(32) NOT NULL,
  `file_name` varchar(128) NOT NULL,
  `file_size` mediumtext NOT NULL,
  `file_type` varchar(32) DEFAULT NULL,
  `file_count` int(11) NOT NULL,
  `file_path` varchar(128) NOT NULL,
  `file_remark` varchar(32) DEFAULT NULL,
  PRIMARY KEY (`file_md5`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `file`
--

LOCK TABLES `file` WRITE;
/*!40000 ALTER TABLE `file` DISABLE KEYS */;
/*!40000 ALTER TABLE `file` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `file_dir`
--

DROP TABLE IF EXISTS `file_dir`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `file_dir` (
  `file_dir_id` int(11) NOT NULL AUTO_INCREMENT,
  `dir_id` int(11) NOT NULL,
  `file_md5` varchar(32) NOT NULL,
  PRIMARY KEY (`file_dir_id`),
  KEY `FK_directory_file_dir` (`dir_id`),
  KEY `FK_file_file_dir` (`file_md5`),
  CONSTRAINT `FK_directory_file_dir` FOREIGN KEY (`dir_id`) REFERENCES `directory` (`dir_id`),
  CONSTRAINT `FK_file_file_dir` FOREIGN KEY (`file_md5`) REFERENCES `file` (`file_md5`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `file_dir`
--

LOCK TABLES `file_dir` WRITE;
/*!40000 ALTER TABLE `file_dir` DISABLE KEYS */;
/*!40000 ALTER TABLE `file_dir` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user` (
  `user_id` varchar(16) NOT NULL,
  `user_passwd` varchar(32) NOT NULL,
  `user_time` datetime NOT NULL,
  `user_ip` varchar(32) NOT NULL,
  `user_vip` int(11) NOT NULL,
  `user_name` varchar(32) NOT NULL,
  PRIMARY KEY (`user_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user_file`
--

DROP TABLE IF EXISTS `user_file`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user_file` (
  `user_file_id` bigint(20) NOT NULL AUTO_INCREMENT,
  `user_file_name` varchar(128) NOT NULL,
  `user_file_time` datetime NOT NULL,
  `user_file_permission` varchar(16) NOT NULL,
  `user_file_status` tinyint(1) NOT NULL,
  `user_file_hide` tinyint(1) NOT NULL,
  `user_file_ip` varchar(32) NOT NULL,
  `user_file_path` varchar(128) NOT NULL,
  `file_md5` varchar(32) NOT NULL,
  `user_file_remark` varchar(32) DEFAULT NULL,
  `user_id` varchar(16) NOT NULL,
  PRIMARY KEY (`user_file_id`),
  KEY `FK_file_user_file` (`file_md5`),
  KEY `FK_user_user_file` (`user_id`),
  CONSTRAINT `FK_file_user_file` FOREIGN KEY (`file_md5`) REFERENCES `file` (`file_md5`),
  CONSTRAINT `FK_user_user_file` FOREIGN KEY (`user_id`) REFERENCES `user` (`user_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user_file`
--

LOCK TABLES `user_file` WRITE;
/*!40000 ALTER TABLE `user_file` DISABLE KEYS */;
/*!40000 ALTER TABLE `user_file` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `user_info`
--

DROP TABLE IF EXISTS `user_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user_info` (
  `user_info_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_email` varchar(32) NOT NULL,
  `user_birthday` date DEFAULT NULL,
  `user_phone` int(11) DEFAULT NULL,
  `login_time` datetime NOT NULL,
  `login_ip` varchar(32) NOT NULL,
  `login_status` int(11) NOT NULL,
  `user_id` varchar(16) NOT NULL,
  PRIMARY KEY (`user_info_id`),
  KEY `FK_user_user_info` (`user_id`),
  CONSTRAINT `FK_user_user_info` FOREIGN KEY (`user_id`) REFERENCES `user` (`user_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user_info`
--

LOCK TABLES `user_info` WRITE;
/*!40000 ALTER TABLE `user_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `user_info` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-01-13 12:59:40
