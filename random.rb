#!/usr/bin/ruby

if ARGV.length != 3
	puts "random.ruby: wrong number of arguments, requires 3 integers \n\t- usage: random.ruby [min value] [max value] [number of values]"
	exit 1
end

if	ARGV[0].to_i >= ARGV[1].to_i
	puts "random.ruby: min value must be less than max value"
	exit 1
end

if	ARGV[2].to_i <= 0
	puts "random.ruby: number of values muast be greater than 0"
	exit 1
end

puts (ARGV[0].to_i..ARGV[1].to_i).to_a.sample(ARGV[2].to_i).join(' ')