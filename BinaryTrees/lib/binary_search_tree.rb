class BinarySearchTree 
    class Node
        def initialize(value, left, right)
            @value = value
            @left = left
            @right = right
        end
    end

    def initialize 
        @value = nil
    end

    def empty?
        return @value == nil
    end
end
