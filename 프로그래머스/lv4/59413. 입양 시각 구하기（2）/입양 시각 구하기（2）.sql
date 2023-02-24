-- 코드를 입력하세요
SET @time := -1;
SELECT @time := @time + 1, (select count(*) from animal_outs where hour(datetime) = @time) from animal_outs where @time < 23;