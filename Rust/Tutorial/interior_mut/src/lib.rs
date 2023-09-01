// Library that tracks current value to maximum value
pub trait Messenger {
    fn send(&self, msg: &str);
}

pub struct LimitTracker<'a, T: Messenger> {
    messenger: &'a T,
    value: usize,
    max: usize,
}

impl<'a, T> LimitTracker<'a, T>
where
    T: Messenger,
{
    pub fn new(messenger: &T, max: usize) -> LimitTracker<T> {
        LimitTracker {
            messenger,
            value: 0,
            max,
        }
    }

    pub fn set_value(&mut self, value: usize) {
        self.value = value;
        let percentage = self.value as f64 / self.max as f64;
        if percentage >= 1.0 {
            self.messenger.send("Error: Quota Limit Exceeded");
        }
        else if percentage >= 0.9 {
            self.messenger.send("Warning: You have used over 90% of your Quota");
        }
        else if percentage >= 0.75 {
            self.messenger.send("Warning: You have used over 75% of your Quota");
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::cell::RefCell;

    struct MockMessenger {
        sent_messages: RefCell<Vec<String>>,
    }

    impl MockMessenger {
        fn new() -> MockMessenger {
            MockMessenger { sent_messages: RefCell::new(vec![]) }
        }
    }

    impl Messenger for MockMessenger {
        fn send(&self, msg: &str) {
            self.sent_messages.borrow_mut().push(msg.to_string());

            let mut mut_one = self.sent_messages.borrow_mut();
            let mut mut_two = self.sent_messages.borrow_mut();

            mut_one.push(msg.to_string());
            mut_two.push(msg.to_string());
        }
    }

    #[test]
    fn over_75_warning() {
        let mock_mess = MockMessenger::new();
        let mut limit_tracker = LimitTracker::new(&mock_mess, 100);
        
        limit_tracker.set_value(80);

        assert_eq!(mock_mess.sent_messages.borrow().len(), 1);
        assert_eq!(mock_mess.sent_messages.borrow()[0], "Warning: You have used over 75% of your Quota");
    }
}