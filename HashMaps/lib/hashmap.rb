class HashMap
  DEFAULT_CAPACITY = 16
  LOAD_FACTOR = 0.75

  attr_reader :size, :hash_function

  def initialize(capacity = DEFAULT_CAPACITY, hash_function: :djb2)
    @capacity = capacity
    @buckets = Array.new(@capacity) { [] }
    @size = 0
    @hash_function = method(hash_function)
  end

  def set(key, value)
    resize! if load_factor > LOAD_FACTOR

    index = index_for(key)
    bucket = @buckets[index]

    pair = bucket.find { |k, _| k == key }
    if pair
      pair[1] = value
    else
      bucket << [key, value]
      @size += 1
    end
  end

  def get(key)
    index = index_for(key)
    bucket = @buckets[index]
    pair = bucket.find { |k, _| k == key }
    pair&.last
  end

  def delete(key)
    index = index_for(key)
    bucket = @buckets[index]
    pair = bucket.find { |k, _| k == key }

    if pair
      bucket.delete(pair)
      @size -= 1
      return pair.last
    end

    nil
  end

  def keys
    @buckets.flatten(1).map(&:first)
  end

  def values
    @buckets.flatten(1).map(&:last)
  end

  private

  def load_factor
    @size.to_f / @capacity
  end

  def index_for(key)
    hash_code = @hash_function.call(key.to_s)
    hash_code % @capacity
  end

  def resize!
    old_buckets = @buckets
    @capacity *= 2
    @buckets = Array.new(@capacity) { [] }
    @size = 0

    old_buckets.each do |bucket|
      bucket.each do |key, value|
        set(key, value)
      end
    end
  end

  # --- Hash Functions ---

  def additive_hash(str)
    str.bytes.sum
  end

  def djb2(str)
    hash = 5381
    str.each_byte { |b| hash = ((hash << 5) + hash) + b } # hash * 33 + b
    hash & 0xFFFFFFFF
  end

  def fnv1a(str)
    hash = 2166136261
    prime = 16777619
    str.each_byte do |b|
      hash ^= b
      hash *= prime
      hash &= 0xFFFFFFFF
    end
    hash
  end
end