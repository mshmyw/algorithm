# coding: utf-8
# 快速判定素数，用素数判定素数。比如求1-100之间的素数，
# 先求1-10之间的素数为[2,3,5,7]，
# 再用11-100的数%[2,3,5,7]，不能被整除的就是素数

# 直接判定一个数是否为素数
def is_prime?(n)
    t = 2
    while (t <= Math.sqrt(n).to_i)
      if (n % t == 0)
        # puts n.to_s + "->" + t.to_s
        return false
      end
        t = t + 1
    end
    if n <= 1
        return false
    end
    return true
end

def get_prime(n1,n2)
    result = [] # result用于保存begin-end之间的所有素数
    temp = []  # 保存2-Math.sqrt(end)之间的所有素数
    temp_index = 0
    result_index = 0
    for i in 2 .. Math.sqrt(n2).to_i
        if is_prime?(i)
            temp[temp_index] = i
            temp_index = temp_index + 1
        end
    end
    temp.each{|i|
        if i >= n1
            result[result_index] = i
            result_index = result_index + 1
        end
        # print i," "
    }
    # puts

    start =  Math.sqrt(n2).to_i
    if start > n1
        n1 = start
    end
    for i in n1 .. n2
        flag = true
        temp.each{|t|
            if i % t == 0
                flag = false
                break
            end
        }
        if flag
            result[result_index] = i
            result_index = result_index + 1
        end
    end
    return result
end
result = [7, 277, 2777, 7727, 72727, 727272727, 72727272727272727, 72277, 27277, 22777]
for num in result
  if is_prime?(num)
    puts num.to_s + " is prime"
  elsif
    puts num.to_s + " not  prime"
  end
end


# puts "请输入两个数并按回车键(格式为a b)："
# while true
#     num = gets.split(" ")
#     n1 = num[0].to_i
#     n2 = num[1].to_i
#     result = get_prime(n1,n2)
#     result.each{|i|
#         print i," "
#     }
#     puts
# end
