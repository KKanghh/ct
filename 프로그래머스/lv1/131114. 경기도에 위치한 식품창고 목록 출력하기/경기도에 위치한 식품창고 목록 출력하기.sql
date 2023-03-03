-- 코드를 입력하세요
SELECT warehouse_id, warehouse_name, address, if (freezer_yn is null, 'N', freezer_yn) from food_warehouse where left(address, 3) = '경기도';