-- 코드를 입력하세요
SELECT mcdp_cd, count(*) from appointment where year(apnt_ymd) = '2022' and month(apnt_ymd) = '5' group by mcdp_cd order by count(*), mcdp_cd;