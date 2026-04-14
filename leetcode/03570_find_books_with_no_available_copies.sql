select lb.book_id, title, author, genre, publication_year, current_borrowers
from library_books lb
join (
    select book_id, count(1) as current_borrowers 
    from borrowing_records
    where return_date is null
    group by book_id
) br
on br.book_id = lb.book_id
where current_borrowers = lb.total_copies
order by current_borrowers desc, title;
