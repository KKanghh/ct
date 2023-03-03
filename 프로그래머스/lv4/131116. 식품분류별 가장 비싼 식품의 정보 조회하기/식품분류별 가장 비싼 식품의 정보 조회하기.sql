-- 코드를 입력하세요
SELECT category, price as MAX_PRICE, product_name from food_product where (price, category) in (
    select max(price), category from food_product group by category having (category = '과자' or category = '국' or category = '김치' or category='식용유')
) order by price desc;
# select * from food_product;