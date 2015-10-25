n = gets.to_i
money = 0
price = 101
while n > 0 do
	n -= 1
	a,p = gets.chomp.split(' ').map!{ |o| o.to_i }
	price = p if price > p
	money += price * a
end

puts money
