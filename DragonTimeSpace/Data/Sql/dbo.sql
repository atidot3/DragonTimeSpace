-- --------------------------------------------------------
-- Hôte :                        127.0.0.1
-- Version du serveur:           10.4.12-MariaDB - mariadb.org binary distribution
-- SE du serveur:                Win64
-- HeidiSQL Version:             10.2.0.5599
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;


-- Listage de la structure de la base pour dbo
CREATE DATABASE IF NOT EXISTS `dbo` /*!40100 DEFAULT CHARACTER SET utf8 */;
USE `dbo`;

-- Listage de la structure de la table dbo. account
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
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;

-- Les données exportées n'étaient pas sélectionnées.

-- Listage de la structure de la table dbo. characters
CREATE TABLE IF NOT EXISTS `characters` (
  `CharacterID` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `AccountID` int(11) unsigned NOT NULL DEFAULT 0,
  `GuildID` int(11) unsigned NOT NULL DEFAULT 0,
  `Name` varchar(20) NOT NULL,
  `HeroID` int(11) unsigned NOT NULL,
  `AvatarID` int(11) unsigned NOT NULL,
  `Gender` int(11) unsigned NOT NULL,
  `Facestyle` int(11) unsigned NOT NULL,
  `Hairstyle` int(11) unsigned NOT NULL,
  `Haircolor` int(11) unsigned NOT NULL,
  `Antenna` int(11) unsigned NOT NULL,
  `CurrentLevel` int(11) unsigned NOT NULL DEFAULT 1,
  `CurrentExp` int(11) unsigned NOT NULL DEFAULT 0,
  `MapID` int(11) unsigned NOT NULL DEFAULT 695,
  `Position_X` float(11,6) NOT NULL DEFAULT 830.000000,
  `Position_Y` float(11,6) NOT NULL DEFAULT 830.000000,
  `Direction_X` float(11,6) NOT NULL DEFAULT 0.000000,
  `Direction_Y` float(11,6) NOT NULL DEFAULT 0.000000,
  `Money` int(11) unsigned NOT NULL DEFAULT 0,
  `Welpoint` int(11) unsigned NOT NULL DEFAULT 0,
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
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;

-- Les données exportées n'étaient pas sélectionnées.

-- Listage de la structure de la table dbo. chattabs
CREATE TABLE IF NOT EXISTS `chattabs` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `AccountID` int(11) unsigned NOT NULL DEFAULT 0,
  `chattab` varchar(1024) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `AccountID_idx` (`AccountID`),
  CONSTRAINT `FKAccountID` FOREIGN KEY (`AccountID`) REFERENCES `account` (`AccountID`) ON DELETE CASCADE ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- Les données exportées n'étaient pas sélectionnées.

-- Listage de la structure de la table dbo. quickslots
CREATE TABLE IF NOT EXISTS `quickslots` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `CharacterID` int(11) unsigned NOT NULL DEFAULT 0,
  `quickslot` varchar(1024) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `FK_CharacterID` (`CharacterID`) USING BTREE,
  CONSTRAINT `fk_quickslot_characters_1` FOREIGN KEY (`CharacterID`) REFERENCES `characters` (`CharacterID`) ON DELETE CASCADE ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;

-- Les données exportées n'étaient pas sélectionnées.

-- Listage de la structure de la table dbo. realmlist
CREATE TABLE IF NOT EXISTS `realmlist` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `LineID` int(11) unsigned NOT NULL DEFAULT 0,
  `realmflags` tinyint(3) unsigned NOT NULL DEFAULT 2,
  `population` float(10,0) unsigned NOT NULL DEFAULT 0,
  `Ip` varchar(20) NOT NULL,
  `Port` int(11) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Realm System';

-- Les données exportées n'étaient pas sélectionnées.

-- Listage de la structure de la table dbo. shortcuts
CREATE TABLE IF NOT EXISTS `shortcuts` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `AccountID` int(11) unsigned NOT NULL DEFAULT 0,
  `shortcut` varchar(4096) NOT NULL DEFAULT '{"0":{"key":"99"},"1":{"key":"107"},"2":{"key":""},"3":{"key":"98"},"4":{"key":"108"},"5":{"key":"103"},"6":{"key":"117"},"7":{"key":"106"},"8":{"key":"111"},"9":{"key":"109"},"11":{"key":"119"},"12":{"key":"115"},"13":{"key":"97"},"14":{"key":"100"},"15":{"key":"32"},"16":{"key":"9"},"17":{"key":"304,49"},"18":{"key":"304,50"},"19":{"key":"304,51"},"20":{"key":"304,52"},"21":{"key":"96"},"22":{"key":"101"},"23":{"key":"122"},"24":{"key":"306,290"},"25":{"key":"306,291"},"26":{"key":"306,288"},"27":{"key":"306,289"},"28":{"key":"306,292"},"101":{"key":"282"},"102":{"key":"283"},"103":{"key":"284"},"104":{"key":"285"},"105":{"key":"286"},"106":{"key":"287"},"107":{"key":"288"},"108":{"key":"289"},"109":{"key":"290"},"110":{"key":"291"},"111":{"key":"292"},"112":{"key":"293"},"201":{"key":""},"202":{"key":""},"203":{"key":""},"204":{"key":""},"205":{"key":""},"206":{"key":""},"207":{"key":""},"208":{"key":""},"209":{"key":""},"210":{"key":""},"211":{"key":""},"212":{"key":""},"301":{"key":""},"302":{"key":""},"303":{"key":""},"304":{"key":""},"305":{"key":""},"306":{"key":""},"307":{"key":""},"308":{"key":""},"309":{"key":""},"310":{"key":""},"311":{"key":""},"312":{"key":""},"401":{"key":""},"402":{"key":""},"403":{"key":""},"404":{"key":""},"405":{"key":""},"406":{"key":""},"407":{"key":""},"408":{"key":""},"409":{"key":""},"410":{"key":""},"411":{"key":""},"412":{"key":""},"501":{"key":"49"},"502":{"key":"50"},"503":{"key":"51"},"504":{"key":"52"},"505":{"key":"53"},"506":{"key":"54"},"507":{"key":"55"},"508":{"key":"56"},"509":{"key":"57"},"510":{"key":"48"},"511":{"key":"45"},"512":{"key":"61"},"513":{"KEY":""}}"',
  PRIMARY KEY (`id`),
  KEY `AccountID_shortcut` (`AccountID`),
  CONSTRAINT `shortcut_AccountID` FOREIGN KEY (`AccountID`) REFERENCES `account` (`AccountID`) ON DELETE CASCADE ON UPDATE NO ACTION
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

-- Les données exportées n'étaient pas sélectionnées.

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IF(@OLD_FOREIGN_KEY_CHECKS IS NULL, 1, @OLD_FOREIGN_KEY_CHECKS) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
