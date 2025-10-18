SELECT
    p.product_id,
  
    ROUND(
        COALESCE(
            SUM(us.units * pr.price)::NUMERIC / SUM(us.units),
            0
        ),
        2
    ) AS average_price
FROM
  
    (SELECT DISTINCT product_id FROM Prices) p
LEFT JOIN
  
    UnitsSold us ON p.product_id = us.product_id
LEFT JOIN
   
    Prices pr ON us.product_id = pr.product_id
       
        AND us.purchase_date BETWEEN pr.start_date AND pr.end_date
GROUP BY
    p.product_id
ORDER BY
    p.product_id;