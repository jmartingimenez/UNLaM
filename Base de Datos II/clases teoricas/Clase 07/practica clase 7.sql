CREATE FUNCTION Rangos (@id tinyint)
RETURNS nvarchar(10)
AS
  BEGIN
  DECLARE @Valor nvarchar(10)
  SELECT @Valor = CASE WHEN @id<20 THEN '1-19'
      WHEN @id>=20 AND @id<40 THEN '20-39'
      WHEN @id>=40 AND @id<60 THEN '40-59'
      WHEN @id>=60 AND @id<80 THEN '60-79'
      WHEN @id>=80 AND @id<100 THEN '80-99'
      ELSE '>100'
      END
  RETURN @Valor
END

--Formas de llamar
select dbo.Rangos(10)

declare @rangosdec nvarchar(10)
select @rangosdec = dbo.Rangos(10)
select @rangosdec

select Rangos(cant) from productos