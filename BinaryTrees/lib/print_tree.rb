def print_tree(node, left_accessor: nil, right_accessor: nil, value_accessor: nil, prefix: "", is_left: true)
  return if node.nil?

  left_accessor  ||= ->(n) { n.left }
  right_accessor ||= ->(n) { n.right }
  value_accessor ||= ->(n) { n.to_s }

  right_child = right_accessor.call(node)
  left_child  = left_accessor.call(node)

  print_tree(right_child, left_accessor: left_accessor, right_accessor: right_accessor,
             value_accessor: value_accessor,
             prefix: prefix + (is_left ? "│   " : "    "), is_left: false)

  puts prefix + (is_left ? "└── " : "┌── ") + value_accessor.call(node)

  print_tree(left_child, left_accessor: left_accessor, right_accessor: right_accessor,
             value_accessor: value_accessor,
             prefix: prefix + (is_left ? "    " : "│   "), is_left: true)
end

class TreeNode
  attr_accessor :val, :left, :right

  def initialize(val)
    @val = val
  end

  def to_s
    val.to_s
  end
end

root = TreeNode.new(10)
root.left = TreeNode.new(5)
root.right = TreeNode.new(20)

puts "\n"

print_tree(root)  # No accessors needed

class MyNode
  attr_accessor :value, :l, :r

  def initialize(value)
    @value = value
  end
end


root = MyNode.new("Root")
root.l = MyNode.new("Left")
root.r = MyNode.new("Right")

print_tree(
  root,
  left_accessor: ->(n) { n.l },
  right_accessor: ->(n) { n.r },
  value_accessor: ->(n) { n.value }
)

puts "\n-----------------------------\n\n"

root = TreeNode.new(1)
root.left = TreeNode.new(2)
root.right = TreeNode.new(3)
root.left.left = TreeNode.new(4)
root.left.right = TreeNode.new(5)

# Print the tree
print_tree(root)

puts "\n--------------------------------\n\n"

root = TreeNode.new('A')
root.left = TreeNode.new('B')
root.right = TreeNode.new('C')
root.left.left = TreeNode.new('D')
root.left.right = TreeNode.new('E')
root.right.left = TreeNode.new('F')
root.right.right = TreeNode.new('G')

print_tree(root)

puts "\n--------------------------------\n\n"

root = TreeNode.new(10)
root.left = TreeNode.new(9)
root.left.left = TreeNode.new(8)
root.left.left.left = TreeNode.new(7)

print_tree(root)

puts "\n--------------------------------\n\n"

root = MyNode.new("root")
root.l = MyNode.new("L")
root.r = MyNode.new("R")
root.l.l = MyNode.new("LL")
root.r.r = MyNode.new("RR")

print_tree(
  root,
  left_accessor: ->(n) { n.l },
  right_accessor: ->(n) { n.r },
  value_accessor: ->(n) { n.value }
)