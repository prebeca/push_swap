# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    mean.rb                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 23:04:46 by user42            #+#    #+#              #
#    Updated: 2021/04/28 23:04:47 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

if ARGV.length != 2
	puts "mean.ruby: wrong number of arguments, requires 2 integers \n\t- usage: mean.ruby [number of tests] [number of values]"
	exit 1
end

working = ['|', '/', '-', '\\', '|', '/', '-', '\\']

mean = 0;
min = -1;
max = -1;

for i in 1..ARGV[0].to_i
	print "running test #{i}/#{ARGV[0].to_i} ... #{working[i % working.length]}\r"
	$stdout.flush
	moves = `ARG=$(ruby random.rb -9999 9999 #{ARGV[1].to_i}) && ./push_swap $ARG | wc -l`.to_i
	if (moves > max)
		max = moves
	end
	if (min == -1 || moves < min)
		min = moves
	end
	mean += moves;
end

mean = mean / ARGV[0].to_i

puts "\nmean = #{mean} average moves for #{ARGV[0].to_i} tests of #{ARGV[1].to_i} values"
puts "min = #{min.to_i} moves"
puts "max = #{max.to_i} moves"