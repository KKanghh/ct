-- 코드를 입력하세요
(SELECT date_format(sales_date, '%Y-%m-%d') as SALES_DATE, PRODUCT_ID, user_id, sales_amount from online_sale where YEAR(SALES_date) = '2022' and MONTH(SALES_date) = '03'
UNION
SELECT date_format(sales_date, '%Y-%m-%d') as SALES_DATE, PRODUCT_ID, null as user_id, sales_amount from offline_sale where YEAR(SALES_date) = '2022' and MONTH(SALES_date) = '03') order by sales_date, product_id, user_id;