----------------------------------------------------------------------------------------------------------------------------------------------
---EJEMPLO 5:
--A partir de la versión del ejemplo 4 agregar lo siguiente:
--Id no puede ser negativo, nulo ni cero.
--Nombre no puede ser nulo, ni vacio y debe tener una longitud mayor a 2. Ademas no puede contener números.
--Apellido no puede ser nulo, ni vacio y debe tener una longitud mayor a 2. Ademas no puede contener números.
--Fecha de nacimiento debe ser mayor o igual a 1/1/1915
--La edad es un campo calculado en alta o modificación. No se recibe mas por parametro.}
--El DNI no puede ser NULL ni 0. Debe tener una longitud de 8.
--POr otro lado no se puede dar de alta o modificar dos empleados con igual DNI.
--Se debe validar que el proyecto del empleado sea un proyecto existente en la tabla de proyecto (tanto en el alta como en la modificacion)
CREATE TABLE [dbo].[EMPLEADO](
	[ID] [numeric](18, 0) NOT NULL, --not null, no negativo
	[NOMBRE] [varchar](100) NOT NULL, --not null
	[APELLIDO] [varchar](100) NOT NULL, --not null
	[FECHA_NAC] DATETIME NOT NULL, --no sea inferior a 1914
	[EDAD] INT NOT NULL, --campo calculado, no se recibe por parametro
	DN I INT NOT NULL, --no null, no cero o negativo y validar la longitud
 CONSTRAINT [PK_EMPLEADO] PRIMARY KEY CLUSTERED 
(
---------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------------------
--Creación de tabla Empleado 
----------------------------------------------------------------------------------------------------------------------------------------------
DROP TABLE [dbo].[PROYECTO]
GO
CREATE TABLE [dbo].[PROYECTO](
	[ID] [numeric](18, 0) NOT NULL,
	[DESCRIPCION] [varchar](100) NOT NULL
 CONSTRAINT [PK_PROYECTO] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
 GO
DROP TABLE [dbo].[EMPLEADO]
GO
CREATE TABLE [dbo].[EMPLEADO](
	[ID] NUMERIC(18, 0) NOT NULL, 
	[NOMBRE] VARCHAR(100) NOT NULL, 
	[APELLIDO] VARCHAR(100) NOT NULL, 
	[FECHA_NAC] DATETIME NOT NULL, 
	[EDAD] SMALLINT NOT NULL, 
	[DNI] INT NOT NULL, 
	[IDPROYECTO] [numeric](18, 0) NULL,
 CONSTRAINT [PK_EMPLEADO] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO

ALTER TABLE [dbo].[EMPLEADO]  WITH CHECK ADD  CONSTRAINT [FK_EMPLEADO_PROYECTO] FOREIGN KEY([IDPROYECTO])
REFERENCES [dbo].[PROYECTO] ([ID])
GO

ALTER TABLE [dbo].[EMPLEADO] CHECK CONSTRAINT [FK_EMPLEADO_PROYECTO]
GO
DROP TABLE [dbo].[LOGERRORES]
GO
CREATE TABLE [dbo].[LOGERRORES](
	[ID] [numeric](18, 0) IDENTITY(1,1) NOT NULL,
	[DESCRIPCION] [varchar](max) NULL,
	[ERROR] [int] NULL,
	[FILA] [int] NULL,
	[ERROR_LINE] [int] NULL,
	[ERROR_MESSAGE] [nvarchar](2048) NULL,
	[ERROR_PROCEDURE] [nvarchar](126) NULL,
	[ERROR_NUMBER] [int] NULL,
	[ERROR_SEVERITY] [int] NULL,
	[ERROR_STATE] [int] NULL,
	[FECALT] [datetime] NULL,
	[USERID] [varchar](255) NULL
 CONSTRAINT [PK_LOGERRORES] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO