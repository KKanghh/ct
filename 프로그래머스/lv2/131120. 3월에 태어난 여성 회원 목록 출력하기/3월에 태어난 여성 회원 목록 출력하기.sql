-- 코드를 입력하세요
SELECT member_id, member_name, gender, date_format(date_of_birth, '%Y-%m-%d') FROM MEMBER_PROFILE where MONTH(DATE_OF_BIRTH) = 3 and tlno is not null and gender = 'w' order by member_id;