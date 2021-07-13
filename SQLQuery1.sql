
USE [Dog shelter]
GO
/****** Object:  Table [dbo].[Dog info]    Script Date: 7/12/2021 10:11:08 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Dog info](
	[id] [int] NOT NULL,
	[name] [varchar](50) NOT NULL,
	[gender] [varchar](50) NOT NULL,
	[age] [int] NOT NULL,
	[breed] [varchar](50) NOT NULL,
	[condition] [varchar](50) NOT NULL,
	[date_of_arrival] [date] NOT NULL,
 CONSTRAINT [PK_Dog info] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
/****** Object:  Table [dbo].[Dog_adoption_status]    Script Date: 7/12/2021 10:11:08 AM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Dog_adoption_status](
	[id] [int] NOT NULL,
	[Dog_adoption_status] [varchar](50) NOT NULL,
 CONSTRAINT [PK_Dog_adoption_status] PRIMARY KEY CLUSTERED 
(
	[id] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (1, N'Bark', N'Male', 2, N'Husky', N'good', CAST(N'2021-03-22' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (2, N'Maya', N'Female', 1, N'Labrador', N'good', CAST(N'2021-04-18' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (3, N'Corny', N'Male', 5, N'French Bulldog', N'bad', CAST(N'2021-07-03' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (4, N'Zeus', N'Male', 10, N'Golden Retreiver', N'good', CAST(N'2020-09-22' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (5, N'Lilly', N'Female', 9, N'Pomeranian', N'good', CAST(N'2021-04-01' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (6, N'Tommy', N'Male', 4, N'German Shepherd', N'bad', CAST(N'2021-02-28' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (7, N'Bobby', N'Male', 3, N'Doberman', N'bad', CAST(N'2021-08-08' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (8, N'Lanna', N'Female', 1, N'Boxer', N'good', CAST(N'2021-01-01' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (9, N'Fluffy', N'Male', 4, N'French Bolognese', N'good	', CAST(N'2021-04-13' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (10, N'Diamond', N'Female', 2, N'Poodle', N'good', CAST(N'2021-03-03' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (11, N'Max', N'Male', 1, N'Rottweiler	', N'bad', CAST(N'2020-06-04' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (12, N'Shine	', N'Female', 8, N'Cane Corso', N'good', CAST(N'2021-05-25' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (13, N'Sarah', N'Female', 5, N'English Cocker Spaniel', N'bad', CAST(N'2020-07-08' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (14, N'Ara', N'Female', 2, N'Yorkshire Terrier', N'good', CAST(N'2021-04-22' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (15, N'Tomas', N'Male', 10, N'Doberman', N'good', CAST(N'2020-02-03' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (16, N'Mayra', N'Female', 4, N'Pug', N'good', CAST(N'2021-06-30' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (17, N'Stan', N'Male', 11, N'Great Dane', N'good', CAST(N'2021-01-27' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (18, N'Lola', N'Female', 3, N'Poodle', N'good', CAST(N'2021-03-28' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (19, N'Peter', N'Male', 7, N'Pug', N'bad', CAST(N'2021-02-03' AS Date))
GO
INSERT [dbo].[Dog info] ([id], [name], [gender], [age], [breed], [condition], [date_of_arrival]) VALUES (20, N'Jack', N'Male', 13, N'Great Dane', N'bad', CAST(N'2020-09-30' AS Date))
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (1, N'not adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (2, N'adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (3, N'not adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (4, N'not adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (5, N'adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (6, N'not adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (7, N'not adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (8, N'adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (9, N'adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (10, N'not adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (11, N'not adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (12, N'not adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (13, N'adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (14, N'not adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (15, N'not adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (16, N'adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (17, N'not adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (18, N'not adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (19, N'not adopted')
GO
INSERT [dbo].[Dog_adoption_status] ([id], [Dog_adoption_status]) VALUES (20, N'adopted')
GO
ALTER TABLE [dbo].[Dog_adoption_status] ADD  CONSTRAINT [DF_Dog_adoption_status_Dog_adoption_status]  DEFAULT ('not adopted') FOR [Dog_adoption_status]
GO
ALTER TABLE [dbo].[Dog_adoption_status]  WITH CHECK ADD  CONSTRAINT [FK_Dog_adoption_status_Dog info_id] FOREIGN KEY([id])
REFERENCES [dbo].[Dog info] ([id])
GO
ALTER TABLE [dbo].[Dog_adoption_status] CHECK CONSTRAINT [FK_Dog_adoption_status_Dog info_id]
GO
ALTER TABLE [dbo].[Dog info]  WITH CHECK ADD  CONSTRAINT [CK_Dog info_age] CHECK  (([age]>(0) AND [age]<=(16)))
GO
ALTER TABLE [dbo].[Dog info] CHECK CONSTRAINT [CK_Dog info_age]
GO
USE [master]
GO
ALTER DATABASE [Dog shelter] SET  READ_WRITE 
GO
