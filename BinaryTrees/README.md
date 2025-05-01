# Binary Trees

### Printing Binary Trees

```ruby
def print_tree(node, left_accessor: nil, right_accessor: nil, value_accessor: nil, prefix: "", is_left: true)
  return if node.nil?

  left_accessor  ||= -> (n) { n.left }
  right_accessor ||= -> (n) { n.right }
  value_accessor ||= -> (n) { n.to_s }

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
```

This function can be called in two ways. The first is passing just a root node which will assume that there are attribute accessors for `left` and `right`, and a `to_s` method for returning a string for the value of the node. The second is explicitly passing the pattern for accesing the left and right nodes and a method that returns a string value for that node.


##### Default Accessors
```ruby
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

print_tree(root)  # No accessors needed
```

##### With Accessors
```ruby
class MyNode
  attr_accessor :value, :l, :r

  def initialize(value)
    @value = value
  end
end


root = MyNode.new("Root")
root.l = MyNode.new("Left")
root.r = MyNode.new("Right")

print_tree(  # with accessors
  root,
  left_accessor: -> (n) { n.l },
  right_accessor: -> (n) { n.r },
  value_accessor: -> (n) { n.value }
)
```