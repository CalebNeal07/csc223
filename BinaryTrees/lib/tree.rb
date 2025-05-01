class TreeNode
  attr_accessor :val, :left, :right

  def initialize(val)
    @val = val
    @left = nil
    @right = nil
  end
end

def print_tree(node, left_accessor: nil, right_accessor: nil, prefix: "", is_left: true)
  return if node.nil?

  # Default accessors use `.left` and `.right`
  left_accessor ||= ->(n) { n.left }
  right_accessor ||= ->(n) { n.right }

  right_child = right_accessor.call(node)
  left_child = left_accessor.call(node)

  print_tree(right_child, left_accessor: left_accessor, right_accessor: right_accessor,
             prefix: prefix + (is_left ? "│   " : "    "), is_left: false)

  puts prefix + (is_left ? "└── " : "┌── ") + node.to_s

  print_tree(left_child, left_accessor: left_accessor, right_accessor: right_accessor,
             prefix: prefix + (is_left ? "    " : "│   "), is_left: true)
end

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

class MyNode
  attr_accessor :value, :l, :r

  def initialize(value)
    @value = value
    @l = nil
    @r = nil
  end

  def to_s
    value.to_s
  end 
end

# Create a tree
root = MyNode.new("root")
root.l = MyNode.new("L")
root.r = MyNode.new("R")
root.l.l = MyNode.new("LL")
root.r.r = MyNode.new("RR")

# Print using custom accessors
print_tree(
  root,
  left_accessor: -> (n) { n.l },
  right_accessor: -> (n) { n.r }
)