-- Dumping database structure for dbo
CREATE DATABASE IF NOT EXISTS `dbo` /*!40100 DEFAULT CHARACTER SET utf8mb4 */;
USE `dbo`;

-- Dumping structure for table dbo.account
DROP TABLE IF EXISTS `account`;
CREATE TABLE IF NOT EXISTS `account` (
  `AccountID` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `UserName` varchar(16) NOT NULL,
  `UserPassword` char(64) NOT NULL,
  `IsGM` tinyint(1) NOT NULL DEFAULT 0,
  `AdminLevel` int(11) unsigned NOT NULL DEFAULT 0,
  `AccountStatus` tinyint(1) NOT NULL DEFAULT 0,
  `email` varchar(50) DEFAULT NULL,
  `ip` varchar(50) DEFAULT NULL,
  `mac` varchar(16) DEFAULT NULL,
  `authkey` varchar(16) DEFAULT NULL,
  `totaltime` int(11) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`AccountID`),
  UNIQUE KEY `AccountID_UNIQUE` (`AccountID`)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

-- Data exporting was unselected.
-- Dumping structure for table dbo.characters
DROP TABLE IF EXISTS `characters`;
CREATE TABLE IF NOT EXISTS `characters` (
  `CharacterID` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `AccountID` int(11) unsigned NOT NULL DEFAULT 0,
  `GuildID` INT(11) unsigned NOT NULL DEFAULT 0,
  `Name` varchar(20) NOT NULL,
  `HeroID` int(11) unsigned NOT NULL,
  `AvatarID` int(11) unsigned NOT NULL,
  `Gender` int(11) unsigned NOT NULL,
  `Facestyle` int(11) unsigned NOT NULL,
  `Hairstyle` int(11) unsigned NOT NULL,
  `Haircolor` int(11) unsigned NOT NULL,
  `Antenna` int(11) unsigned NOT NULL,
  `CurrentLevel` int(11) unsigned NOT NULL DEFAULT 1,
  `CurrentExp` INT(11) unsigned NOT NULL DEFAULT 0,
  `MapID` INT(11) unsigned NOT NULL DEFAULT 695,
  `Position_X` float(11,6) NOT NULL DEFAULT 830.000000,
  `Position_Y` float(11,6) NOT NULL DEFAULT 830.000000,
  `Direction_X` float(11,6) NOT NULL DEFAULT 0.000000,
  `Direction_Y` float(11,6) NOT NULL DEFAULT 0.000000,
  `Money` INT(11) unsigned NOT NULL DEFAULT 0,
  `Welpoint` INT(11) unsigned NOT NULL DEFAULT 0,
  `Stone` int(11) unsigned NOT NULL DEFAULT 0,
  `Tilizhi` int(11) NOT NULL DEFAULT 0,
  `Edupoint` int(11) NOT NULL DEFAULT 0,
  `Cooppoint` int(11) NOT NULL DEFAULT 0,
  `Bluecrystal` int(11) NOT NULL DEFAULT 0,
  `Purplecrystal` int(11) NOT NULL DEFAULT 0,
  `Vigourpoint` int(11) NOT NULL DEFAULT 0,
  `Doublepoint` int(11) NOT NULL DEFAULT 0,
  `Bluecrystalincnum` int(11) NOT NULL DEFAULT 0,
  `Purplecrystalincnum` int(11) NOT NULL DEFAULT 0,
  `createdAt` varchar(20) DEFAULT NULL,
  `deletionStartedAt` bigint(15) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`CharacterID`),
  UNIQUE KEY `CharacterID_UNIQUE` (`CharacterID`),
  UNIQUE KEY `CharacterName_UNIQUE` (`Name`),
  KEY `FKAccountID` (`AccountID`) USING BTREE,
  CONSTRAINT `fk_characters_account_1` FOREIGN KEY (`AccountID`) REFERENCES `account` (`AccountID`) ON DELETE CASCADE ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8;

-- Data exporting was unselected.
-- Dumping structure for table dbo.realmlist
DROP TABLE IF EXISTS `realmlist`;
CREATE TABLE IF NOT EXISTS `realmlist` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `LineID` int(11) unsigned NOT NULL DEFAULT 0,
  `realmflags` tinyint(3) unsigned NOT NULL DEFAULT 2,
  `population` float(10,0) unsigned NOT NULL DEFAULT 0,
  `Ip` varchar(20) NOT NULL,
  `Port` int(11) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Realm System';